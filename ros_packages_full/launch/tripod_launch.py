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
                {"leg_no": 1},
                {"servo_ids": [0, 1, 2]}
            ]
        ),
        Node(
            package='RobotLeg',
            executable='robot_leg_wrapper',
            name='leg_2',
            parameters=[
                {"leg_no": 2},
                {"servo_ids": [3, 4, 5]}
            ]
        ),
        Node(
            package='RobotLeg',
            executable='robot_leg_wrapper',
            name='leg_3',
            parameters=[
                {"leg_no": 3},
                {"servo_ids": [6, 7, 8]}
            ]
        ),
        Node(
            package='three_legs_controller',
            executable='three_legs_controller'
        )

    ])