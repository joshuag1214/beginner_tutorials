# Ros2 beginner tutorials
Submission for Week 11 Assigment  

### **Results**
Captures, Cpplint and Cppcheck results are saved in the results folder

### **Dependencies:**
| Name | Version |  
|ROS2 | Humble |  
|Python3 | 3.10 |

### **Steps to Build:** 
In the root of the package (/ros_ws), run this in a terminal:
```
colcon build 
```
### **Steps to Run Talk (TF2) with Default Values :** 
In /ros_ws
```
. install/setup.bash
ros2 launch ./src/launch/week_11.launch.py
```
To view talk values
```
ros2 run tf2_tools view_frames
ros2 topic echo /tf_static 
```
Captures are saved under the results folder as "Screenshot ros2 topic echo tf_static.png" and "frames_2022-11-30_01.06.09.pdf"

### **Steps to Run Launch File with Rosbag2:** 
In /ros_ws, use Ctrl+C to stop.
```
. install/setup.bash
ros2 launch ./src/launch/week_11.launch.py
```
Note* the ros2 bag or "talker" node might still be running after Ctrl+C.
 
In a new terminal, run this to activate the subscriber:
```
. install/setup.bash
ros2 run week11 listener
```
In a new terminal, run this to activate the recording:
```
ros2 bag play <Enter Rosbag folder here>
```
The capture of this process is saved in the results folder as "rosbag2_capture.png"



### **Know Issues**
-Extra service could not be implemented correctly  
-Logging methods were implemented but frequency could not be changed to a default. -Program will continue to run with undesired frequency.  
-For an unkown reason, cppcheck does not work with static_turtle_tf2_broadcaster.cpp. It cannot find its path  
-Launch file week_11.launch.py behaves oddly  
-Gtest could not be implemented  
