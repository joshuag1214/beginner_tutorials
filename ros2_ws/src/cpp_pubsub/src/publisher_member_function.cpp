/**
 * @file publisher_member_function.cpp
 * @author Joshua Gomes (GitID:joshuag1214)
 * @brief 
 * @version 1
 * @date 2022-11-08
 * 
 * @copyright Copyright (c) 2022, Apache License 2.0
 * 
 */

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

using namespace std::chrono_literals;

/**
 * @brief MinimalPublisher is imherited from Node and uses create_subscription to execute a callback.
 * 
 */
class MinimalPublisher : public rclcpp::Node{
 public:
/**
 * @brief Construct a new MinimalPublisher object, initiallizing its defualt values.  
 * The contructor names the node "minimal_publisher" and makes the initial count at zero. 
 * Every this in the code is referring to the node.
 */
  MinimalPublisher()
  : Node("minimal_publisher"), count_(0) {
    /// The publisher is initiallized as String type, with
    /// topic name "topic" and a queue limit of 10
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    /// timer is initialized here making timer_callback trigger
    /// every half second
    timer_ = this->create_wall_timer(
      500ms, std::bind(&MinimalPublisher::timer_callback, this));
  }

 private:
/**
 * @brief timer_callback prints the desired message "Hello, sir!."
 * 
 */
  void timer_callback() {
    auto message = std_msgs::msg::String();
    message.data = "Hello, sir! " + std::to_string(count_++);
    /// RCLCPP_INFO ensures that the messages show up on the terminal
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    publisher_->publish(message);
  }
  /// The following are declarations of the class's timer,
  /// publisher and counter
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  size_t count_;
};
int main(int argc, char * argv[]) {
  /// rclcpp::init initializes ros2
  rclcpp::init(argc, argv);
  /// rclcpp::spin processes data from the node
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}
