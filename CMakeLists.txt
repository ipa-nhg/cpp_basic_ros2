cmake_minimum_required(VERSION 3.5)
project(cpp_basic)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()
set(CMAKE_CXX_STANDARD 11) # C++11...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS ON) #...with compiler extensions like gnu++11

# Find necessary ROS packages and libraries
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# Add the source files to the build
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")

# Create the executable
add_executable(basic_node src/basic_node.cpp)

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

