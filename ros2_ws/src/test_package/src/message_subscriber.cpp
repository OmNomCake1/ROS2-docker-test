// Subscriber node class implementation
// Written by Ryan Wong

// standard includes
#include <string>

// other includes
#include "message_subscriber.hpp"

// Constructor implementation
MessageSubscriber::MessageSubscriber() : Node{"message_subscriber"} {

    subscriber_ = create_subscription<std_msgs::msg::String> (
        "/count_topic",
        10,
        std::bind(&MessageSubscriber::message_callback, this, std::placeholders::_1)
    );
}

// callback when receiving a message from "/count_topic"
void MessageSubscriber::message_callback(const std_msgs::msg::String::SharedPtr msg) {
    // the data field is of type std::string
    std::string message = msg->data;
    // You need to convert to a c_string when logging
    RCLCPP_INFO(get_logger(), "Message received: %s", message.c_str());
}

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MessageSubscriber>();

    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}