FROM ros:jazzy-ros-core-noble

WORKDIR /root/ros2_docker_test


# Install curl and get new gpg key (temp as the docker image doesn't have the new key yet)
# RUN rm -f /usr/share/keyrings/ros2-latest-archive-keyring.gpg && \
#     curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg


# Then install ros2-apt-source, a new package for future gpg key management
# RUN apt-get update && \
#     apt-get install -y ros2-apt-source && \
#     apt-get update

# Use bash and source ROS setup automatically on shell start
SHELL ["/bin/bash", "-c"]
RUN echo "source /opt/ros/jazzy/setup.bash" >> ~/.bashrc
