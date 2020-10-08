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

# Simulation Results

- RTAB Map
![RTAB map](https://user-images.githubusercontent.com/49041896/95522707-cf273980-099a-11eb-9c7e-11b0336877ff.png)

- Occupancy Grids
![occupancy grids](https://user-images.githubusercontent.com/49041896/95522759-f41bac80-099a-11eb-8852-6e48257d7e0a.png)
