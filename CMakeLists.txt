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

# build package sources
add_subdirectory(src/nodes)

# driver unit tests
#
#  * When -DDEVICE_TEST=true is configured: run tests that require
#    some real 1394 camera to be attached.
#
#  * Otherwise, run only tests that require no attached camera, as is
#    done on the ROS build machines.
#

if (${DEVICE_TEST})
  add_rostest(tests/camera_node_hz.test)
  add_rostest(tests/camera_nodelet_hz.test)
endif (${DEVICE_TEST})

add_rostest(tests/no_device_node.test)
add_rostest(tests/no_device_nodelet.test)
