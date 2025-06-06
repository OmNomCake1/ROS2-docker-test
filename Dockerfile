FROM ros:jazzy-ros-base

WORKDIR /root/ros2_docker_test


RUN apt update

# Use bash and source ROS setup automatically on shell start
SHELL ["/bin/bash", "-c"]
RUN echo "source /opt/ros/jazzy/setup.bash" >> ~/.bashrc
