/*********************************************************************
* Software License Agreement (BSD License)
*
 *  Copyright (c) 2013 Boris Gromov, BioRobotics Lab at Korea Tech
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*   * Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*   * Redistributions in binary form must reproduce the above
*     copyright notice, this list of conditions and the following
*     disclaimer in the documentation and/or other materials provided
*     with the distribution.
*   * Neither the name of the author nor other contributors may be
*     used to endorse or promote products derived from this software
*     without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
*  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
*  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
*  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
*  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
*  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*********************************************************************/

#ifndef _TRIGGER_H_
#define _TRIGGER_H_

#include <dc1394/dc1394.h>

/** @file

    @brief libdc1394 triggering modes interface

    Functions to get or set libdc1394 triggering modes corresponding to various
    Config parameters, limiting configured values to those actually
    supported by the device.

    @author Boris Gromov

*/

namespace Trigger
{
  bool enumSources(dc1394camera_t *camera, dc1394trigger_sources_t &sources);
  dc1394trigger_polarity_t getPolarity(dc1394camera_t *camera);
  bool setPolarity(dc1394camera_t *camera, dc1394trigger_polarity_t &polarity);
  dc1394switch_t getExternalTriggerPowerState(dc1394camera_t *camera);
  bool setExternalTriggerPowerState(dc1394camera_t *camera, dc1394switch_t &state);
  dc1394switch_t getSoftwareTriggerPowerState(dc1394camera_t *camera);
  bool setSoftwareTriggerPowerState(dc1394camera_t *camera, dc1394switch_t &state);
  dc1394trigger_mode_t getMode(dc1394camera_t *camera);
  bool setMode(dc1394camera_t *camera, dc1394trigger_mode_t &mode);
  dc1394trigger_source_t getSource(dc1394camera_t *camera);
  bool setSource(dc1394camera_t *camera, dc1394trigger_source_t &source);
}

#endif // _TRIGGER_H_
