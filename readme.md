# RoboJackets IGVC [![Build Status](https://circleci.com/gh/RoboJackets/igvc-software/tree/master.svg?&style=shield)](https://circleci.com/gh/RoboJackets/igvc-software/tree/master)
![](https://user-images.githubusercontent.com/4125463/68362261-aea09080-00f4-11ea-9d82-379f88d2d532.jpg)

Welcome to the RoboJackets IGVC software repo!
This document will give you a brief description of the repo's layout and an overview of the repo.
For more detailed information, check out the [github wiki](https://github.com/RoboJackets/igvc-software/wiki)
or the [RoboJackets wiki](wiki.robojackets.org).

<!-- The online API documentation generated by Doxygen is located [here](robojackets.github.io/igvc-software/). -->

## Folder Structure
The repo is comprised of multiple ROS packages and one sandbox folder for miscellaneous resources.
 * **igvc_description**
    *URDF files for our robot and gazebo meshes used for simulation*
 * **igvc_gazebo**
    *Helper nodes used for simulation purposes*
 * **igvc_msgs**
    *Custom ROS messages used in the various ROS packages*
 * **igvc_navigation**
    *Collection of nodes that form our navigation stack*
 * **igvc_perception**
    *Collection of nodes that form our perception stack, most notably the line detector*
 * **igvc_platform**
    *Nodes that are platform specific and used to communicate with the hardware, ie. IMU, joystick and motor controller*
 * **igvc_rviz_plugins**
    *RVIZ plugins that provide visualization for our stack.*
 * **igvc_utils**
    *A collection of utility nodes and classes*
 * **sandbox**
    *Miscellaneous resources, including the models used by the neural network, udev rules, and waypoints files*
 * **documents**
    *Research and design documents.*
    
## Building Code
 For an installation guide for ROS, check out the
 [installation guide on the RoboJackets wiki](https://wiki.robojackets.org/IGVC_Software_Installation_Instructions).
 
1. Clone the repository (with the git submodules) into the src directory of a catkin workspace:
    ```bash
    git clone https://github.com/RoboJackets/igvc-software --recursive
    ```

2. Use `catkin_make` in the workspace to build all the packages:
    ```bash
    catkin_make
    ```

3. Make sure the `devel/setup.bash` is sourced before using any of the nodes in this package:
    ```bash
   source devel/setup.bash
    ```
   
## Common Errors
- `Could not find a package configuration file provided by "parameter_assertions" with any of the following names:`
    - `parameter_assertions` comes from a git submodule. Initialize the submodules by doing
    `git submodule update --init --recursive`
- `Could not find a package configuration file provided by "XXXX" with any of the following names:"`
    - Make sure you have ran `rosdep install --from-paths src --ignore-src` in the `catkin_ws` folder already
    - If you still get this error after installing all dependencies, then that means that we forgot to include
    that package in our dependencies list.
    [File an issue](https://github.com/RoboJackets/igvc-software/issues) with the error message.


## Running Gazebo
You can get started with the IGVC code base right away by launching our simulator!

**Load up Jessii:**
The following command will load our platform into a simulated IGVC qualifications course:
```
roslaunch igvc_gazebo qualification.launch
```

**Navigation the course:**
To launch the navigation stack for simulation:
```bash
roslaunch igvc_navigation navigation_simulation.launch
```

Alternatively, you can control the robot manually with a USB gamepad with this command:
```
roslaunch igvc joystick_driver.launch
```

## Contributing
Join the chat [here!](https://robojackets.slack.com/)
