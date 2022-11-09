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