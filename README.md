# ROS_ND_Map_my_World
RTAB mapping gazebo environment

- First, launch the Gazebo world and RViz, spawn the robot in the environment:
```
roslaunch my_robot world.launch
```

- Then, launch the teleop node:
```
roslaunch my_robot teleop.launch
```
- Finally, launch the mapping node:
```
roslaunch my_robot mapping.launch
```
- With this you can map the enviroment using RTAB mapping.

- With rtabmap-databaseViewer you can view your data which is saved in my_robot/maps folder

![2D RTAB map](https://user-images.githubusercontent.com/49041896/95013524-c5a27800-060e-11eb-865b-00cc88bbcf45.JPG)
![Screenshot (58)](https://user-images.githubusercontent.com/49041896/95013549-f387bc80-060e-11eb-83c6-ca0278cf2d13.png)
