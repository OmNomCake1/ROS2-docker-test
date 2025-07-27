from launch import LaunchDescription
from launch_ros.actions import Node, LifecycleNode


def generate_launch_description():
    return LaunchDescription([
        LifecycleNode(
            package='ros2_socketcan',
            executable='socket_can_receiver_node_exe',
            name='socket_can_receiver_node',
            namespace='',
            parameters=[{'autostart': True}]
        ),
        Node(
            package="can_counter",
            executable="can_counter_exe",
            name="can_counter_node"
        )
    ])