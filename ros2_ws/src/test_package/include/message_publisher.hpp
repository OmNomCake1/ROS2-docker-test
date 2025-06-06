// message_publisher node class definition
// Simply publishes to topic /count_topic every 500ms
// Written by Ryan Wong 

#ifndef MESSAGE_PUBLISHER_HPP_
#define MESSAGE_PUBLISHER_HPP_

// ros includes
#include "rclcpp/rclcpp.hpp" // ROS2 C++ client library
#include "std_msgs/msg/string.hpp" // string message type


// convention - end private member variables with _
class MessagePublisher : public rclcpp::Node { 
public:
    // constructor
    MessagePublisher();
    void timerCallback();

private:
    // timer and publisher needs to be shared pointers
    rclcpp::TimerBase::SharedPtr timer_ {};
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_ {};
    int count_ {};
};

#endif