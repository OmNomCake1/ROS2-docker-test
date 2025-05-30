FROM ros:jazzy-ros-base

WORKDIR /root/ros2_docker_test

COPY . .

RUN apt update
    
# Set up shell to source ROS since default is sh not bash
# source is a bash feature
SHELL ["/bin/bash", "-c"]
RUN echo "source /opt/ros/jazzy/setup.bash" >> ~/.bashrc