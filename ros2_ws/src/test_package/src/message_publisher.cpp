// Implementation to simple publisher node
// Written by Ryan Wong 

// c standard library includes
#include <iostream>
#include <chrono>

// hpp include
#include "message_publisher.hpp"

using namespace std::chrono_literals; // allows us to use "500ms"

MessagePublisher::MessagePublisher() : Node("MessagePublisher"), count_{0} {
    // create publisher
    publisher_ = create_publisher<std_msgs::msg::String>("/count_topic", 10);
    
    // create wall timer
    timer_ = create_wall_timer(500ms, std::bind(&MessagePublisher::timerCallback, this));
}

void MessagePublisher::timerCallback() {
    // log that we're gonna publish
    count_++;
    // RCLCPP_INFO(get_logger(), "Timer triggered %d times", count_);

    // publish count
    std_msgs::msg::String msg = std_msgs::msg::String();
    msg.data = "Timer count = " + std::to_string(count_);
    publisher_->publish(msg);
}


int main(int argc, char* argv[]) {
    // init client library
    rclcpp::init(argc, argv);

    // make pointer to instance of the node class above
    auto node = std::make_shared<MessagePublisher>();
    
    // start the node
    rclcpp::spin(node);

    // shutdown when node terminates
    rclcpp::shutdown();

    return 0;
}

