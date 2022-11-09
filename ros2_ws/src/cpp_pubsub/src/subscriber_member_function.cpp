/**
 * @file subscriber_member_function.cpp
 * @author Joshua Gomes (GitID:joshuag1214)
 * @brief 
 * @version 1
 * @date 2022-11-08
 * 
 * @copyright Copyright (c) 2022, Apache License 2.0
 * 
 */

#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

/**
 * @brief MinimalSubscriber is imherited from Node and uses std::bind() to register a
 * member function as a callback from the timer. It provides and output confirming that publisher is read.
 */
class MinimalSubscriber : public rclcpp::Node {
 public:
  /**
   * @brief Construct a new Minimal Subscriber object, initiallizing its defualt values.  
   * The contructor names the node "minimal_subscriber."  * 
   */
  MinimalSubscriber()
  : Node("minimal_subscriber") {
    /// The subscriber is initiallized as String type, with topic name "topic"
    /// and a queue limit of 10
    subscription_ = this->create_subscription<std_msgs::msg::String>(
      "topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
  }

 private:
/**
 * @brief The main function of minimal_subscriber, which prints a message onto a terminal that the publisher is being read 
 * 
 * @param msg is the message that timer_callback prints, being read as an input for topic_callback 
 */
  void topic_callback(const std_msgs::msg::String & msg) const {
    /// prints onto the terminal what is being read
    RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
  }
  /// The  declarations of the class's subscriber
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[]) {
  /// rclcpp::init initializes ros2
  rclcpp::init(argc, argv);
  /// rclcpp::spin processes data from the node
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
