// receives CAN messages and counts them
// Written by Ryan Wong
#ifndef CAN_COUNTER_HPP
#define CAN_COUNTER_HPP

#include "rclcpp/rclcpp.hpp"
#include "can_msgs/msg/frame.hpp"
#include  "std_msgs/msg/int64.hpp"

class CanCounter : public rclcpp::Node {
public:
    CanCounter();
private:
    int num_msgs_{};
    rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr num_msgs_publisher_;
    rclcpp::Subscription<can_msgs::msg::Frame>::SharedPtr can0_sub_;

    void publish_num_msgs_(const can_msgs::msg::Frame::SharedPtr msg);
};


#endif
