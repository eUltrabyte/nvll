#pragma once
#ifndef NVLL_CORE_HEADER
#define NVLL_CORE_HEADER

#include "nvllpch.hpp"

#include "Platform.hpp"
#include "Console.hpp"
#include "Command.hpp"

namespace nvll {
    enum State {
        Menu = 0,
        New,
        Open,
        Help,
        Exit
    };

    class App {
    public:
        App(Console* console);
        virtual ~App() = default;

        virtual int Init();
        virtual void PrintLogo();

    protected:
        Console* m_console;

    private:
        State m_state;
        std::shared_ptr<CommandHandler> m_handler;

    };
};

#endif
