// A simple publisher node which publishes to /count_topic at 2Hz a counter
// Written by Ryan Wong 

// c standard library includes
#include <iostream>
#include <chrono>

// ros includes
#include "rclcpp/rclcpp.hpp" // ROS2 C++ client library
#include "std_msgs/msg/string.hpp" // string message type

// convention - end private member variables with _

using namespace std::chrono_literals; // allows us to use "500ms"

class CppMinimalPublisher : public rclcpp::Node { 
public:
    // constructor
    CppMinimalPublisher() : Node("cpp_minimal_publisher"), count_{0} {
        // create publisher
        publisher_ = create_publisher<std_msgs::msg::String>("/count_topic", 10);

        // create wall timer
        timer_ = create_wall_timer(500ms, std::bind(&CppMinimalPublisher::timerCallback, this));
    }

    void timerCallback() {
        // log that we're gonna publish
        count_++;
        RCLCPP_INFO(get_logger(), "Timer triggered %d times", count_);

        // publish count
        std_msgs::msg::String msg = std_msgs::msg::String();
        msg.data = "Timer count = " + std::to_string(count_);
        publisher_->publish(msg);
    }

private:
    // timer and publisher needs to be shared pointers
    rclcpp::TimerBase::SharedPtr timer_ {};
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_ {};
    int count_ {};
};

int main(int argc, char* argv[]) {
    // init client library
    rclcpp::init(argc, argv);

    // make pointer to instance of the node class above
    auto node = std::make_shared<CppMinimalPublisher>();
    
    // start the node
    rclcpp::spin(node);

    // shutdown when node terminates
    rclcpp::shutdown();

    return 0;
}

