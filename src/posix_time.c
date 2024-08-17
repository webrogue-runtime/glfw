//========================================================================
// GLFW 3.5 POSIX - www.glfw.org
//------------------------------------------------------------------------
// Copyright (c) 2002-2006 Marcus Geelnard
// Copyright (c) 2006-2017 Camilla Löwy <elmindreda@glfw.org>
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would
//    be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source
//    distribution.
//
//========================================================================

#include "internal.h"

#if defined(GLFW_BUILD_POSIX_TIMER)

#include <unistd.h>
#include <sys/time.h>


//////////////////////////////////////////////////////////////////////////
//////                       GLFW platform API                      //////
//////////////////////////////////////////////////////////////////////////

void _glfwPlatformInitTimer(void)
{
    _glfw.timer.posix.clock = CLOCK_REALTIME;

#if defined (__wasi__)
    _glfw.timer.posix.frequency = 1000000;
#else
    _glfw.timer.posix.frequency = 1000000000;
#endif

#if defined(_POSIX_MONOTONIC_CLOCK) && !defined (__wasi__)
    struct timespec ts;
    if (clock_gettime(CLOCK_MONOTONIC, &ts) == 0)
        _glfw.timer.posix.clock = CLOCK_MONOTONIC;
#endif
}

uint64_t _glfwPlatformGetTimerValue(void)
{
#if defined (__wasi__)
    struct timeval val;
    gettimeofday(&val, NULL);
    uint64_t usec = val.tv_sec * 1000000 + val.tv_usec;
    return usec;
#else
    struct timespec ts;
    clock_gettime(_glfw.timer.posix.clock, &ts);
    return (uint64_t) ts.tv_sec * _glfw.timer.posix.frequency + (uint64_t) ts.tv_nsec;
#endif
}

uint64_t _glfwPlatformGetTimerFrequency(void)
{
    return _glfw.timer.posix.frequency;
}

#endif // GLFW_BUILD_POSIX_TIMER

