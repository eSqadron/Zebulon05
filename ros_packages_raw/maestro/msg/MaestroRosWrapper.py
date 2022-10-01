import rclpy
from rclpy.node import Node

from std_msgs.msg import String

from msg import MaestroTarget, CurrentPosition

from MaestroController import Controller


class MaestroRosWrapper(Node):
    def __init__(self):
        super().__init__('maestro_ros_wrapper')
        self.target_subscription = self.create_subscription(
            MaestroTarget,
            'maestro_target',
            self.target_callback,
            2)

        self.current_pos_publisher = self.create_publisher(
            CurrentPosition,
            'current_positions',
            2)

        timer_period = 0.5  # seconds
        self.timer = self.create_timer(
            timer_period,
            self.pos_publisher_timer_callback)

        self.maestro = Controller()

        #self.target_subscription  # prevent unused variable warning

    def pos_publisher_timer_callback(self):
        msg = CurrentPosition()
        msg.current_ang = [self.maestro.getPosition(i) for i in range(24)]

        self.current_pos_publisher.publish(msg)

    def target_callback(self, msg):
        # self.get_logger().info('I heard: "%s"' % msg.data)
        self.maestro.setTarget(msg.channel, msg.target_ang)
        self.maestro.setSpeed(msg.channel, msg.speed)
        self.maestro.setAccel(msg.channel, msg.acceleration)


def main(args=None):
    rclpy.init(args=args)

    maestro_ros_wrapper = MaestroRosWrapper()

    rclpy.spin(maestro_ros_wrapper)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    maestro_ros_wrapper.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
