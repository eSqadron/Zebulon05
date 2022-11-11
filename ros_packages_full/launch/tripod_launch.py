from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='polulu_maestro',
            executable='maestro_wrapper',
            name='polulu_maestro'
        ),
        Node(
            package='RobotLeg',
            executable='robot_leg_wrapper',
            name='RobotLeg_1'
        ),
        Node(
            package='three_legs_controller',
            executable='three_legs_controller',
            name='three_legs_controller'
        )

    ])