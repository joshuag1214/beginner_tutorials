
import sys

from launch import LaunchDescription

from launch.actions import ExecuteProcess
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration

def generate_launch_description():

    count_arg = LaunchConfiguration('count', default='40')
    return LaunchDescription([
        ExecuteProcess(
            cmd=['ros2', 'bag', 'record', '-a'],
            output='screen'
        )
        
        ,

        Node(
            package="week11",
            executable="talker",
            name="talker_node",
            output="screen",
            emulate_tty=True,
            parameters=[{'count': count_arg}]
        )

    ])
