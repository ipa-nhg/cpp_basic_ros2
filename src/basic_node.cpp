/*
 * Copyright 2024 Fraunhofer Institute for Manufacturing Engineering and Automation (IPA)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0

 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class HelloWorldPublisher : public rclcpp::Node {
public:
  HelloWorldPublisher() : Node("hello_world_publisher") {
    // Create a publisher for the "chatter" topic
    publisher_ = create_publisher<std_msgs::msg::String>("chatter", 10);

    // Create a timer to publish the message at a regular interval
    timer_ = create_wall_timer(std::chrono::seconds(1),
                               std::bind(&HelloWorldPublisher::publishHelloWorld, this));
  }

private:
  void publishHelloWorld() {
    // Create a message and set the data
    auto message = std_msgs::msg::String();
    message.data = "Hello, World!";

    // Publish the message
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    publisher_->publish(message);
  }

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[]) {
  // Initialize the ROS 2 system
  rclcpp::init(argc, argv);

  // Create an instance of the HelloWorldPublisher class
  auto node = std::make_shared<HelloWorldPublisher>();

  // Spin the node to process callbacks
  rclcpp::spin(node);

  // Shut down the ROS 2 system
  rclcpp::shutdown();

  return 0;
}
