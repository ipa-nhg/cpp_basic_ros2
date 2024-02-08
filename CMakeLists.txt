cmake_minimum_required(VERSION 3.5)
project(cpp_basic)

# Set the minimum required version of C++ (C++14 used as an example)
set(CMAKE_CXX_STANDARD 14)

# Find necessary ROS packages and libraries
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# Add the source files to the build
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")

# Create the executable
add_executable(basic_node ${SOURCE_FILES})

ament_target_dependencies(basic_node
  rclcpp
)

# Link against necessary ROS libraries
target_link_libraries(basic_node
  ${rclcpp_LIBRARIES}
)

# Install the executable
install(TARGETS
  basic_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()

