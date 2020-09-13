/*
 *  Copyright (C) 2015-2020 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#pragma once

#define STREAM_TIME_BASE 1000000
#define STREAM_NOPTS_VALUE 0xFFF0000000000000

#define STREAM_TIME_TO_MSEC(x) ((int)((double)(x)*1000 / STREAM_TIME_BASE))
#define STREAM_SEC_TO_TIME(x) ((double)(x)*STREAM_TIME_BASE)
#define STREAM_MSEC_TO_TIME(x) ((double)(x)*STREAM_TIME_BASE / 1000)

#define STREAM_PLAYSPEED_PAUSE 0 // frame stepping
#define STREAM_PLAYSPEED_NORMAL 1000
