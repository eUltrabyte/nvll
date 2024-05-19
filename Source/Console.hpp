#pragma once
#ifndef NVLL_CONSOLE_HEADER
#define NVLL_CONSOLE_HEADER

#include "nvllpch.hpp"

#include "Platform.hpp"

namespace nvll {
    class Console {
    public:
        Console();
        virtual ~Console();

        virtual void Print(std::string_view message);
        virtual void Endl();
        virtual void Pause();

        template<typename T>
        T Input();

        virtual int Init();

    private:
        vec2i m_size;

    };
};

#endif
