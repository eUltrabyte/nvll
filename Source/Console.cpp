#include "Console.hpp"

namespace nvll {
    Console::Console()
    : m_size({ 0, 0 }) {
        platform::SetupANSI();
        m_size = platform::GetConsoleSize();
        platform::SetTitle();
    }
    
    Console::~Console() {
        platform::ClearANSI();
        platform::TerminateANSI();
    }

    void Console::Print(std::string_view message) {
        std::string data = std::string(message.data());
        for(auto i = 0; i < data.length(); ++i) {
            if(data.at(i) == '&' && data.at(i + 1)) {
                switch(data.at(i + 1)) {
                    case '0': { std::cout << "\x1b[30m"; } break;
                    case '1': { std::cout << "\x1b[38;5;4m"; } break;
                    case '2': { std::cout << "\x1b[38;5;2m"; } break;
                    case '3': { std::cout << "\x1b[38;5;6m"; } break;
                    case '4': { std::cout << "\x1b[38;5;1m"; } break;
                    case '5': { std::cout << "\x1b[38;5;5m"; } break;
                    case '6': { std::cout << "\x1b[38;5;215m"; } break;
                    case '7': { std::cout << "\x1b[38;5;250m"; } break;
                    case '8': { std::cout << "\x1b[38;5;245m"; } break;
                    case '9': { std::cout << "\x1b[38;5;32m"; } break;
                    case 'a': { std::cout << "\x1b[38;5;35m"; } break;
                    case 'b': { std::cout << "\x1b[38;5;51m"; } break;
                    case 'c': { std::cout << "\x1b[38;5;9m"; } break;
                    case 'd': { std::cout << "\x1b[38;5;212m"; } break;
                    case 'e': { std::cout << "\x1b[38;5;227m"; } break;
                    case 'f': { std::cout << "\x1b[37m"; } break;
                    case 'l': { std::cout << "\x1b[1m"; } break;
                    case 'u': { std::cout << "\x1b[4m"; } break;
                    case 'r': { std::cout << "\x1b[0m"; } break;
                }

                data.erase(data.begin() + data.find(data.at(i + 1)));
            } else {
                std::cout << data.at(i);
            }
        }
    }

    void Console::Endl() {
        std::cout << '\n';
    }

    void Console::Pause() {
        std::cin.get();
    }

    void Console::Clear() {
        std::cout << "\x1b[2J\x1b[H";
    }

    vec2i& Console::GetSize() {
        return m_size;
    }
};