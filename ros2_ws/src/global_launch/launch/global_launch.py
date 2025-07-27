from launch import LaunchDescription
from launch.actions import TimerAction
from launch_ros.actions import LifecycleNode, Node

def generate_launch_description():
    lifecycle_node = LifecycleNode(
        package='ros2_socketcan',
        executable='socket_can_receiver_node_exe',
        name='socket_can_receiver_node',
        namespace='',
        output='screen',
        parameters=[],
    )

    counter_node = Node(
        package='can_counter',
        executable='can_counter_exe',
        name='can_counter_node',
        output='screen'
    )

    return LaunchDescription([
        lifecycle_node,
        counter_node,
    ])
