# Sunswift Racing ROS2 Jazzy Docker Test
This is a practice environment to get comfortable with the docker, github and ROS 2 development workflow using VS Code. Below are instructions on how to set up and start developing/playing around in a Ubuntu 24.04 environment with ROS 2 Jazzy already installed. It's a good idea to go through the [Jazzy tutorials](https://docs.ros.org/en/jazzy/Tutorials.html) once you have your environment set up.  

Made by Ryan Wong for the Sunswift embedded high-level software team.

## Full Development Workflow 
### Introduction

ROS 2 runs best (and with least effort) on a linux environment. However, since getting everyone on native linux is not feasible, and VMs are slow and clunky, especially for ROS (from experience!), a quick and easy fix is to use **Docker**.


Docker is a tool for packaging applications and their dependencies into **containers**, ensuring they run reliably across different environments. A Docker **image** is kind of a snapshot of an app and its environment, and a **container** is a running instance of that image. Use `Dockerfile` to define how an image is built, and `docker-compose.yml` to manage multi-container setups.

Something new for SR8's development process I want to try to use the devcontainers vscode extension. It allows you to open vscode **inside** a container, almost like a remote environment. This is great beacause tools like intellisense can understand the location of libraries like `rclcpp` to make coding easier. This is configured in `.devcontainer/devcontainer.json`, which outlines how vscode should open the container, and what it should use .

---------------------------
### Prerequisites

You need these installed:
1. Git/Github
2. Visual Studio Code
3. Docker Desktop

Also, install this **VS Code extension**:
- **Dev Containers** (`ms-vscode-remote.remote-containers`)  

---------------------------
### Workflow

1. Clone this git repository  
2. Open this directory in VS Code  
3. Open the command palette and select `Dev Containers: Rebuild and Reopen in Container`  
   **→ This builds the Docker image using the `Dockerfile` and `docker-compose.yml`.**  
    **→ Once you've built the image once, you DO NOT need to rebuild as it takes ages for nothing choose `Dev Containers: Open Folder in Container` instead. The only time you need to rebuild is if you change `Dockerfile`, `docker-compose.yml` or `devcontainer.json`**  

4. You should now see that your VS Code terminal is open *inside* the container  
   - It’ll look something like: `root@168495d3f21d:~/ros2_docker_test#`  
5. I've already created a ROS workspace called `ros2_ws`, but feel free to delete it:  
   - `rm -rf ros2_ws`  
   - Then follow the [ROS 2 Jazzy tutorials](https://docs.ros.org/en/jazzy/Tutorials.html) to learn how to set up your own workspace and packages
6. In the real high-level repo, you would now edit your code once you're in the environment, then after finishing, close the remote environment. Finally, commit and push this code to github.  
   **→ But since we're not, don't bother commiting and pushing as I want to use this repo for my own testing LOL. And you can't anyway!**  


---------------------------
### How it works
1. > How does my code from github which I cloned to my **host** appear in the container?  

If you look in the Dockerfile, it simply uses `ros:jazzy-ros-base` as the base image, which is a mnimal Ubuntu 24.04 + important ROS 2 packages image. It then **copies** all the code from this repo (on the host) to the container filesystem at /root/ros2_docker_test.  

2. > Why do code changes made IN the container still persist even after it shuts down?  

In `docker-compose.yml`, there is a **bind mount** under *volumes*, which basically *mounts* this repository into the docker filesystem at /root/ros2_docker_test. Simply, a bind mount is a directory which is shared between the host and the container, reflecting changes in real time, both ways.

3. > Why do I not need to rebuild the image everytime I edit code?  

All the image does is start with a fresh ROS 2 Jazzy + Ubuntu 24.04 image. The bind mount is the thing the adds our source code into the container. The only time we want the source code to be built into the docker image is during production (I think).


If you need any help or have any questions, feel free to ask me at ryan.t.wong@student.unsw.edu.au. Or message me on Teams.