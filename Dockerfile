FROM ros:jazzy-ros-base

WORKDIR /root/ros2_docker_test


RUN apt update

# Use bash and source ROS setup automatically on shell start
SHELL ["/bin/bash", "-c"]
RUN echo "source /opt/ros/jazzy/setup.bash" >> ~/.bashrc
# add sourcing ROS install/setup.bash only if it exists (colcon build done)
RUN echo '[ -f /root/ros2_docker_test/ros2_ws/install/setup.bash ] && source /root/ros2_docker_test/ros2_ws/install/setup.bash' >> ~/.bashrc
