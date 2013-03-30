cmake_minimum_required(VERSION 2.8)
project(camera1394)

# Find catkin macros and libraries, also other catkin packages.
find_package(catkin REQUIRED COMPONENTS
  camera_info_manager
  diagnostic_updater
  driver_base
  dynamic_reconfigure
  image_transport
  nodelet
  roscpp
  roslib
  rostest
  sensor_msgs
  tf)

# This driver uses Boost threads
find_package(Boost REQUIRED COMPONENTS thread)

# Resolve system dependency on libdc1394, which apparently does not
# provide a CMake find_package() module.
find_package(PkgConfig REQUIRED)
pkg_check_modules(DC1394_PKGCONF REQUIRED libdc1394-2)
find_path(DC1394_INCLUDE_DIR
  NAMES dc1394.h
  PATHS ${DC1394_PKGCONF_INCLUDE_DIRS}
)
find_library(DC1394_LIBRARY
  NAMES dc1394
  PATHS ${DC1394_PKGCONF_LIBRARY_DIRS}
)

# auto-generate dynamic reconfiguration GUI before catkin_package()
generate_dynamic_reconfigure_options(cfg/Camera1394.cfg)
catkin_package(LIBRARIES ${PROJECT_NAME})

# build package sources
add_subdirectory(src/nodes)

# driver unit tests
#
# $ROS_BUILD_TEST_LABEL controls which label "make test" runs
#
#  * if unset, all tests run
#
#  * tests labelled "device" require any real camera
#
#  * only unlabelled tests or those labelled "hudson" automatically
#    run on the ROS build machines
#

# unit tests are broken in catkin:
add_rostest(tests/no_device_node.test)
add_rostest(tests/no_device_nodelet.test)

#add_rostest_labeled(device tests/camera_node_hz.test)
#add_rostest_labeled(device tests/camera_nodelet_hz.test)
