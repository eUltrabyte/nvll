#include "nvll.hpp"

namespace nvll {
    App::App(Console* console)
    : m_console(console), m_state(State::Menu), m_handler(std::make_unique<CommandHandler>()) { }

    int App::Init() {
        m_handler->Push({ "menu", [&]() { m_state = State::Menu; } });
        m_handler->Push({ "new", [&]() { m_state = State::New; } });
        m_handler->Push({ "open", [&]() { m_state = State::Open; } });
        m_handler->Push({ "help", [&]() { m_state = State::Help; } });
        m_handler->Push({ "exit", [&]() { m_state = State::Exit; } });

        for(;;) {
            switch(m_state) {
                case State::Menu: {
                    m_console->Clear();

                    PrintLogo();

                    for(auto i = 0; i < (m_console->GetSize().x / 2) - 2; ++i) { m_console->Print(" "); }
                    m_console->Print("&dMenu&r\n");
                    m_console->Endl();
                       
                    m_console->Print("\tNew &d<filename> &r- creates new todo file.\n");
                    m_console->Print("\tOpen &d<filename> &r- opens todo file.\n");
                    m_console->Print("\tHelp - show info about program.\n");
                    m_console->Print("\tExit - close program.\n");

                    m_console->Endl();

                    while(true) {
                        for(auto i = 0; i < (m_console->GetSize().x / 2) - 13; ++i) { m_console->Print(" "); }
                        m_console->Print("&d>> &r");

                        if(!m_handler->Check(m_console->Input<std::string>())) {
                            m_console->Print("\tUnknown command, try again.\n");
                        } else {
                            break;
                        }
                    }
                } break;

                case State::New: {
                    m_console->Clear();

                    PrintLogo();

                    for(auto i = 0; i < (m_console->GetSize().x / 2) - 2; ++i) { m_console->Print(" "); }
                    m_console->Print("&dNew&r\n");
                    m_console->Endl();

                    m_console->Print("\tEnter &d<filename> &rto create the file.\n");

                    m_console->Endl();
                    for(auto i = 0; i < (m_console->GetSize().x / 2) - 13; ++i) { m_console->Print(" "); }
                    m_console->Print("&d>> &r");

                    std::ofstream file;
                    file::Create(file, m_console->Input<std::string>());

                    m_console->Print("\t&d>> &r");
                    file::Add(file, m_console->Input<std::string>());

                    m_console->Endl();
                    
                    while(true) {
                        for(auto i = 0; i < (m_console->GetSize().x / 2) - 13; ++i) { m_console->Print(" "); }
                        m_console->Print("&d>> &r");

                        std::string input = m_console->Input<std::string>();
                        if(!m_handler->Check(input)) {
                            m_console->Print("\tUnknown command, try again.\n");
                        } else {
                            break;
                        }
                    }

                    file.close();
                } break;

                case State::Open: {
                    m_console->Clear();

                    PrintLogo();

                    for(auto i = 0; i < (m_console->GetSize().x / 2) - 2; ++i) { m_console->Print(" "); }
                    m_console->Print("&dOpen&r\n");
                    m_console->Endl();

                    m_console->Print("\tEnter &d<filename> &rto open the file.\n");

                    m_console->Endl();
                    for(auto i = 0; i < (m_console->GetSize().x / 2) - 13; ++i) { m_console->Print(" "); }
                    m_console->Print("&d>> &r");

                    m_console->Print(file::Open(m_console->Input<std::string>()));

                    m_console->Endl();

                    while(true) {
                        for(auto i = 0; i < (m_console->GetSize().x / 2) - 13; ++i) { m_console->Print(" "); }
                        m_console->Print("&d>> &r");

                        if(!m_handler->Check(m_console->Input<std::string>())) {
                            m_console->Print("\tUnknown command, try again.\n");
                        } else {
                            break;
                        }
                    }
                } break;

                case State::Help: {
                    m_console->Clear();

                    PrintLogo();

                    for(auto i = 0; i < (m_console->GetSize().x / 2) - 2; ++i) { m_console->Print(" "); }
                    m_console->Print("&dHelp&r\n");
                    m_console->Endl();

                    m_console->Print("\t&7[&ax&7] &r- Done\n");
                    m_console->Print("\t&7[&c-&7] &r- Work in progress\n");
                    m_console->Print("\t&7[ ] &r- Todo.\n");

                    m_console->Endl();

                    while(true) {
                        for(auto i = 0; i < (m_console->GetSize().x / 2) - 13; ++i) { m_console->Print(" "); }
                        m_console->Print("&d>> &r");

                        if(!m_handler->Check(m_console->Input<std::string>())) {
                            m_console->Print("\tUnknown command, try again.\n");
                        } else {
                            break;
                        }
                    }
                } break;

                case State::Exit: {
                    std::exit(0);
                } break;
            }
        }

        return 0;
    }

    void App::PrintLogo() {
        for(auto i = 0; i < (m_console->GetSize().x / 2) - 14; ++i) { m_console->Print(" "); }
        m_console->Print("&5                   __  __&r\n");
        for(auto i = 0; i < (m_console->GetSize().x / 2) - 14; ++i) { m_console->Print(" "); }
        m_console->Print("&5  _____  __  __   / / / /&r\n");
        for(auto i = 0; i < (m_console->GetSize().x / 2) - 14; ++i) { m_console->Print(" "); }
        m_console->Print("&5 / _  /  | |/ /  / / / /&r\n");
        for(auto i = 0; i < (m_console->GetSize().x / 2) - 14; ++i) { m_console->Print(" "); }
        m_console->Print("&5/_//_/   |___/  /_/ /_/&r\n");

        m_console->Endl();
        m_console->Endl();
    }
};

auto main(int argc, char** argv) -> int {
    std::shared_ptr<nvll::Console> console = std::make_shared<nvll::Console>();
    std::shared_ptr<nvll::App> app = std::make_shared<nvll::App>(console.get());
    return app->Init();
}