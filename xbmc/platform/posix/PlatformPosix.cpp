/*
 *  Copyright (C) 2019 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#include "PlatformPosix.h"

#include "filesystem/SpecialProtocol.h"

#include <cstdlib>
#include <time.h>

std::atomic_flag CPlatformPosix::ms_signalFlag;

void CPlatformPosix::Init()
{
  CPlatform::Init();

  // Initialize to "set" state
  ms_signalFlag.test_and_set();
}

bool CPlatformPosix::TestQuitFlag()
{
  // Keep set, return true when it was cleared before
  return !ms_signalFlag.test_and_set();
}

void CPlatformPosix::RequestQuit()
{
  ms_signalFlag.clear();
}

void CPlatformPosix::InitTimezone()
{
  tzset();
}

bool CPlatformPosix::SetEnvHomePath()
{
  // set special://envhome
  if (getenv("HOME"))
  {
    CSpecialProtocol::SetEnvHomePath(getenv("HOME"));
    return true;
  }
  fprintf(stderr, "The HOME environment variable is not set!\n");
  return false;
}

void CPlatformPosix::SetEnvOSName()
{
  setenv("OS", "Linux", true);
}
