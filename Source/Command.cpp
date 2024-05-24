#include "Command.hpp"

namespace nvll {
    CommandHandler::CommandHandler()
    : m_commands(std::vector<Command>()) { }

    bool CommandHandler::Check(std::string_view input) {
        std::string command;
        for(const auto symbol : input) {
            command += std::tolower(symbol);
        }

        for(auto i = 0; i < m_commands.size(); ++i) {
            if(m_commands[i].command.find(command) != std::string::npos) {
                m_commands[i].function();
                return true;
            }
        }

        return false;
    }

    void CommandHandler::Push(const Command& command) {
        m_commands.emplace_back(command);
    }
        
    void CommandHandler::Erase(unsigned int index) {
        m_commands.erase(m_commands.begin() + index);
    }
};