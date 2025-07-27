from launch import LaunchDescription
from launch.actions import TimerAction
from launch_ros.actions import LifecycleNode, Node, ChangeState
from lifecycle_msgs.msg import Transition

def generate_launch_description():
    lifecycle_node = LifecycleNode(
        package='ros2_socketcan',
        executable='socket_can_receiver_node_exe',
        name='socket_can_receiver_node',
        namespace='',
        output='screen',
        parameters=[],
    )

    activate_lifecycle_node = TimerAction(
        period=2.0,  # seconds delay to let the node configure first
        actions=[
            ChangeState(
                lifecycle_node_matcher=lambda node: node.name == 'socket_can_receiver_node',
                transition_id=Transition.TRANSITION_ACTIVATE
            )
        ]
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
        activate_lifecycle_node
    ])
