#pragma once
#ifndef NVLL_PLATFORM_HEADER
#define NVLL_PLATFORM_HEADER

#include "nvllpch.hpp"

#ifdef _WIN32
    #define NVLL_WINDOWS
    #include <windows.h>
#else
    #define NVLL_UNIX
    #include <sys/ioctl.h>
    #include <unistd.h>
#endif

namespace nvll {
    template<typename T>
    struct vec2 {
        T x, y;
    };

    using vec2f = vec2<float>;
    using vec2i = vec2<int>;
    using vec2u = vec2<unsigned int>;

    namespace platform {
        extern void SetupANSI();
        extern void ClearANSI();
        extern void TerminateANSI();
        
        extern vec2i GetConsoleSize();
        extern void SetTitle();
    };
};

#endif
