// Subscriber node class definition
// Simply subscribes to /count_topic and prints out the values
// Written by Ryan Wong

#ifndef MESSAGE_SUBSCRIBER_HPP_
#define MESSAGE_SUBSCRIBER_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class MessageSubscriber : public rclcpp::Node {
public:
    MessageSubscriber();
    void message_callback(const std_msgs::msg::String::SharedPtr msg);
private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_;
    
};

#endif