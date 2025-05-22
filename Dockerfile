FROM ros:jazzy-ros-base

WORKDIR /root/test_ws

COPY . .

# Set up shell to source ROS since default is sh not bash
# source is a bash feature
SHELL ["/bin/bash", "-c"]
RUN echo "source /opt/ros/iron/setup.bash" >> ~/.bashrc