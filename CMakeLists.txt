cmake_minimum_required(VERSION 2.8.3)
project(rosplan_interface_pstn)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  std_srvs
  diagnostic_msgs
  geometry_msgs
  rosplan_dispatch_msgs
  rosplan_knowledge_msgs
  rosplan_planning_system
  actionlib
)

###################################
## catkin specific configuration ##
###################################

## Declare things to be passed to dependent projects
catkin_package(
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS roscpp rospy std_msgs std_srvs diagnostic_msgs geometry_msgs rosplan_dispatch_msgs rosplan_knowledge_msgs actionlib rosplan_planning_system
  DEPENDS
)

###########
## Build ##
###########

## include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS}
  include
)

## Declare cpp executables
add_executable(rpactionmonitor src/RPActionMonitor.cpp)
add_dependencies(rpactionmonitor ${catkin_EXPORTED_TARGETS})

## Specify libraries against which to link a library or executable target
target_link_libraries(rpactionmonitor ${catkin_LIBRARIES} ${Boost_LIBRARIES})
