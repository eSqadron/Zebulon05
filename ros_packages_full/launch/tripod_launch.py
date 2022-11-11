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
            parameters=[
                {"background_b": 200},
                {"background_g": 200},
                {"background_r": 200}
            ]
        ),
        Node(
            package='three_legs_controller',
            executable='three_legs_controller'
        )

    ])