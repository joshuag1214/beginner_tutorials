
/**
 * @file publisher_member_function.cpp
 * @author Joshua Gomes (GitID:joshuag1214), Tommy Chang
 * @brief 
 * @version 1
 * @date 2022-17-18
 * 
 * @copyright Copyright (c) 2022, Apache License 2.0
 * 
 */

#include <type_traits>
#include <rclcpp/logger.hpp>
#include <rcutils/logging_macros.h>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <example_interfaces/srv/add_two_ints.hpp>

// #include <example_interfaces/srv/add_two_ints.hpp>

using std::placeholders::_1;    // for use with bind

/// topic types
using STRING    = std_msgs::msg::String;
using PUBLISHER = rclcpp::Publisher<STRING>::SharedPtr;
using TIMER     = rclcpp::TimerBase::SharedPtr;

/// parameter types
using PARAMETER_EVENT  = std::shared_ptr<rclcpp::ParameterEventHandler>;
using PARAMETER_HNADLE = std::shared_ptr<rclcpp::ParameterCallbackHandle>;

/**
 * @brief MinimalPublisher is imherited from Node and uses create_subscription to execute a callback.
 * 
 */
class MinimalPublisher : public rclcpp::Node {
 public:
/**
 * @brief Construct a new MinimalPublisher object, initiallizing its defualt values.  
 * The contructor names the node "minimal_publisher" and makes the initial count at zero. 
 * Every this in the code is referring to the node.
 * The frequency can be changed 
 */
  MinimalPublisher() :
    Node("minimal_publisher"), count_(0) {
    /**
     * @brief  Prints Hello, world!  with a default frequency of 2Hz 
     * 
     */
    auto param_desc = rcl_interfaces::msg::ParameterDescriptor();
    param_desc.description = "Set callback frequency.";
    this->declare_parameter("freq", 2.0, param_desc);  // default =  2 hz
    auto param = this->get_parameter("freq");
    auto freq = param.get_parameter_value().get<std::float_t>();
    m_param_subscriber_ = std::make_shared<rclcpp::ParameterEventHandler>(this);
    auto paramCallbackPtr =
     std::bind(&MinimalPublisher::param_callback, this, _1);
    m_paramHandle_ = m_param_subscriber_->
     add_parameter_callback("freq", paramCallbackPtr);

    /**
     * @brief Set up a topic to be sent by a periodic timer
     * 
     */
    auto topicName = "topic";
    publisher_ = this->create_publisher<STRING>(topicName, 10);
    auto period = std::chrono::milliseconds(static_cast<int>((1000 / freq)));
    auto topicCallbackPtr = std::bind (&MinimalPublisher::timer_callback, this);
    m_timer_ = this->create_wall_timer(period, topicCallbackPtr);
  }

 private:
  /// Member Variables:
  size_t           count_;
  PUBLISHER        publisher_;
  TIMER            m_timer_;

  PARAMETER_EVENT  m_param_subscriber_;
  PARAMETER_HNADLE m_paramHandle_;
  /**
   * @brief function that is used to publish message to terminal
   * 
   */
  void timer_callback() {
    // gets the parameter "my_parameter" from the node
    auto param = this->get_parameter("freq");
    auto freq = param.get_parameter_value().get<std::float_t>();

    /// Below are a series of logging methods inteneded to check
    /// that the frequency is acceptable
    /// Although the warnings show up in the terminal properly,
    /// it is impossible to change the frequency back to 2
    if ( freq == 0 ) {
      RCLCPP_FATAL_STREAM(this->get_logger(), "Fequency of 0 is invalid");
      // freq= 6.0;
    }
    if ( freq< 0 ) {
      RCLCPP_ERROR_STREAM(this->get_logger(), "Frequency must be positive");
      // freq= 4.0;
    }
    if ( freq >= 12 ) {
      // auto freq = 3.0;
      // freq = 4.0;
      RCLCPP_WARN_STREAM(this->get_logger(),
       "Any frequency higher than 12 is too high");
    }
    /// Publishes Hello, world! with hz
    auto message = STRING();
    message.data = "Hello, world! " + std::to_string(count_++);
    RCLCPP_INFO(this->get_logger(), "Publishing at %.2f Hz: '%s'",
     3.0 , message.data.c_str());
    /// Publish the message
    publisher_->publish(message);
  }
/**
 * @brief Used to update Hz 
 * 
 * @param param - new parameter   
 */
  void param_callback(const rclcpp::Parameter & param) {
    RCLCPP_INFO(this->get_logger(),
      "cb: Received an update to parameter \"%s\" of type %s: %.2f",
      param.get_name().c_str(),
      param.get_type_name().c_str(),
      param.as_double());
    auto period = std::chrono::milliseconds((int) (1000 / param.as_double()));
    auto topicCallbackPtr = std::bind(&MinimalPublisher::timer_callback, this);
    m_timer_ = this->create_wall_timer(period, topicCallbackPtr);
    //  no memory leak here
  }
};
int main(int argc, char* argv[]) {
  // 1.) Initialize ROS 2 C++ client library
  rclcpp::init(argc, argv);
  // 2.) Start processing
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  // 3.) Shutdown ROS 2
  rclcpp::shutdown();
  return 0;
}