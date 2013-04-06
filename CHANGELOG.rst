Change history
==============

1.8.1 Groovy (2013-03-01)
-------------------------

 * Fix rostest dependency problem with Groovy build.

1.8.0 Fuerte (2012-03-14)
-------------------------

This version was also released in Groovy.

 * Power off the camera on shutdown (`#5322`_).
 * Provide leading zeros to GUID when needed (`#5350`_).
 * Add diagnostics report on actual camera frame rate (`#5292`_). Thanks to Thomas Moulard for this enhancement.

1.7.0 Fuerte Alpha (2011-12-14)
-------------------------------

 * camera1394 package becomes a unary stack, no longer part of
camera_drivers.

1.6.0 (2011-07-20)
------------------

 * Handle AVT Guppy F036C in format7 mode. That device does not return
   a valid color filter. Use the bayer_pattern parameter for any
   device not providing one (`#5063`_).
 * Support 16-bit Bayer encodings (`#4738`_).

1.4.2 (2011-06-06)
------------------

 * The driver will stamp messages with the current ROS time if the new
   use_ros_time parameter is set. Fixes USB-1394 camera support
   (`#4841`_)
 * Use proper namespace for camera_info_manager (`#4760`_).

1.4.1 (2011-02-09)
------------------

 * Bug fixes for publishing Format7 Region of Interest in CameraInfo
   (`#4735`_, `#4736`_).

1.4.0 (2011-01-31)
------------------

 * Add nodelet version of driver.
 * Add IIDC Format7 support (`#4222`_), thanks to Ken Tossell.
 * Format7 binning and ROI comply with REP 104.
 * Add Focus and Zoom feature support (`#4631`_), thanks to José Antonio
   Álvarez Ruiz.
 * The driver will only set video_mode or frame_rate to values
   supported by the device.
 * Bayer decoding within the driver deprecated (`#4725`_). Prefer
   image_proc decoding instead. Only image_proc method supported in
   Format7 modes.
 * Better support for Mac OS X (`#4659`_).
 * Re-licensed under LGPL.


.. _`#4222`: https://code.ros.org/trac/ros-pkg/ticket/4222
.. _`#4631`: https://code.ros.org/trac/ros-pkg/ticket/4631
.. _`#4659`: https://code.ros.org/trac/ros-pkg/ticket/4659
.. _`#4725`: https://code.ros.org/trac/ros-pkg/ticket/4725
.. _`#4735`: https://code.ros.org/trac/ros-pkg/ticket/4735
.. _`#4736`: https://code.ros.org/trac/ros-pkg/ticket/4736
.. _`#4738`: https://code.ros.org/trac/ros-pkg/ticket/4738
.. _`#4760`: https://code.ros.org/trac/ros-pkg/ticket/4760
.. _`#4841`: https://code.ros.org/trac/ros-pkg/ticket/4841
.. _`#5063`: https://code.ros.org/trac/ros-pkg/ticket/5063
.. _`#5292`: https://code.ros.org/trac/ros-pkg/ticket/5292
.. _`#5350`: https://code.ros.org/trac/ros-pkg/ticket/5350
.. _`#5322`: https://code.ros.org/trac/ros-pkg/ticket/5322
