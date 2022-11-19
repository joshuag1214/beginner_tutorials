# Ros2 beginner tutorials
Submission for Week 9 Assigment  

A ROS2 program with a publisher that prints "Hello, sir!" and a subscriber that confirms the publisher's output

### **Results**
Cpplint and Cppcheck results are saved in results_cpplint_cppcheck.txt

### **Dependencies:**
| Name | Version |  
|ROS2 | Humble |  
|Python3 | 3.10 |

### **Steps to Build and Run :** 
In the root of the package (/ros_ws), run this in a terminal:
```
colcon build --packages-select cpp_pubsub
```
In a new terminal, run this to activate the publisher:
```
. install/setup.bash
ros2 run cpp_pubsub talker
```

In a new terminal, run this to activate the subscriber:
```
. install/setup.bash
ros2 run cpp_pubsub listener
```

To stop either function, press CTRL+C in the respective terminal to shut it down. 

To use launch file, making the with a frequency of 6hz
```
. install/setup.bash
ros2 launch src/launch/cpp_pubsub.yaml
```

To manually enter a frequency for the publisher.
Example below for 4.0 Hz
```
ros2 param set /minimal_publisher freq 4.0
```

### **rqt_console Capture**
The rqt_console capture is saved as a png called capture_rqt_console.png  

You can see the info and warning logging levels  

### **Know Issues**
Extra service could not be implemented correctly  
Logging methods were implemmented but frequency could not be changed to a default. Program will continue to run with undesired frequency.  
