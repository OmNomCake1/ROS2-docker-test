from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='can_counter',
            executable='can_counter_exe',
            name='can_counter_node'
        )
    ])