/*
 *  Copyright (C) 2019 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#pragma once

#include "platform/Platform.h"

#include <atomic>

class CPlatformPosix : public CPlatform
{
public:
  void Init() override;

  static bool TestQuitFlag();
  static void RequestQuit();
  static void InitTimezone();
  static bool SetEnvHomePath();
  static void SetEnvOSName();

private:
  static std::atomic_flag ms_signalFlag;
};
