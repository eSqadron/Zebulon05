from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='polulu_maestro',
            executable='maestro_wrapper'
        ),
        Node(
            package='RobotLeg',
            executable='robot_leg_wrapper',
            name='leg_1',
            parameters=[
                {"leg_no": 1}
            ]
        ),
        Node(
            package='RobotLeg',
            executable='robot_leg_wrapper',
            name='leg_2',
            parameters=[
                {"leg_no": 2}
            ]
        ),
        Node(
            package='RobotLeg',
            executable='robot_leg_wrapper',
            name='leg_3',
            parameters=[
                {"leg_no": 3}
            ]
        ),
        Node(
            package='three_legs_controller',
            executable='three_legs_controller'
        )

    ])