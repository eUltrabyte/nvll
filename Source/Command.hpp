#pragma once
#ifndef NVLL_COMMAND_HEADER
#define NVLL_COMMAND_HEADER

#include "nvllpch.hpp"

#include "Platform.hpp"

namespace nvll {
    struct Command {
        std::string_view command;
        std::function<void()> function;
    };

    class CommandHandler {
    public:
        CommandHandler();
        virtual ~CommandHandler() = default;

        virtual void Check(std::string_view input);
        virtual void Push(const Command& command);
        virtual void Erase(unsigned int index);

    private:
        std::vector<Command> m_commands;

    };
};

#endif
