#include "can_counter/can_counter.hpp"

CanCounter::CanCounter() : Node("can_counter"), num_msgs_{0} {
    num_msgs_publisher_ = this->create_publisher<std_msgs::msg::Int64>("/can/count", 10);
    can0_sub_ = this->create_subscription<can_msgs::msg::Frame> (
        "from_can_bus",
        10,
        std::bind(&CanCounter::publish_num_msgs_, this, std::placeholders::_1)
    );
}

void CanCounter::publish_num_msgs_(const can_msgs::msg::Frame::SharedPtr msg) {
    (void)msg;
    num_msgs_++;
    std_msgs::msg::Int64 new_msg{};
    new_msg.data = num_msgs_;
    num_msgs_publisher_->publish(new_msg);
}

int main(int argc, char* argv[]) {

    // init client library
    rclcpp::init(argc, argv);
    // make pointer to instance of the node class above
    auto node = std::make_shared<CanCounter>();
    
    // start the node
    rclcpp::spin(node);
    // shutdown when node terminates
    rclcpp::shutdown();
    return 0;

}