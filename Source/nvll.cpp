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
                    m_console->Print("Menu\n");
                    m_console->Endl();
                       
                    m_console->Print("\tNew <filename> - creates new todo file.\n");
                    m_console->Print("\tOpen <filename> - opens todo file.\n");
                    m_console->Print("\tHelp - show help about program.\n");
                    m_console->Print("\tExit - close program.\n");

                    m_console->Endl();
                    for(auto i = 0; i < (m_console->GetSize().x / 2) - 13; ++i) { m_console->Print(" "); }
                    m_console->Print(">> ");
                    m_handler->Check(m_console->Input<std::string>());
                } break;

                case State::New: {
                    m_console->Clear();

                    PrintLogo();

                    for(auto i = 0; i < (m_console->GetSize().x / 2) - 2; ++i) { m_console->Print(" "); }
                    m_console->Print("New\n");
                    m_console->Endl();

                    m_console->Print("\tEnter <filename> to create the file.\n");

                    m_console->Endl();
                    for(auto i = 0; i < (m_console->GetSize().x / 2) - 13; ++i) { m_console->Print(" "); }
                    m_console->Print(">> ");

                    // TODO: create file

                    m_console->Endl();
                    for(auto i = 0; i < (m_console->GetSize().x / 2) - 13; ++i) { m_console->Print(" "); }
                    m_console->Print(">> ");
                    m_handler->Check(m_console->Input<std::string>());
                } break;

                case State::Open: {
                    m_console->Clear();

                    PrintLogo();

                    for(auto i = 0; i < (m_console->GetSize().x / 2) - 2; ++i) { m_console->Print(" "); }
                    m_console->Print("Open\n");
                    m_console->Endl();

                    m_console->Print("\tEnter <filename> to open the file.\n");

                    m_console->Endl();
                    for(auto i = 0; i < (m_console->GetSize().x / 2) - 13; ++i) { m_console->Print(" "); }
                    m_console->Print(">> ");

                    // TODO: open file

                    m_console->Endl();
                    for(auto i = 0; i < (m_console->GetSize().x / 2) - 13; ++i) { m_console->Print(" "); }
                    m_console->Print(">> ");
                    m_handler->Check(m_console->Input<std::string>());
                } break;

                case State::Help: {
                    m_console->Clear();

                    PrintLogo();

                    for(auto i = 0; i < (m_console->GetSize().x / 2) - 2; ++i) { m_console->Print(" "); }
                    m_console->Print("Help\n");
                    m_console->Endl();

                    m_console->Print("\tBlah.\n");
                    m_console->Print("\tBlah.\n");
                    m_console->Print("\tBlah.\n");
                    m_console->Print("\tBlah.\n");
                    m_console->Print("\tBlah.\n");

                    m_console->Endl();
                    for(auto i = 0; i < (m_console->GetSize().x / 2) - 13; ++i) { m_console->Print(" "); }
                    m_console->Print(">> ");
                    m_handler->Check(m_console->Input<std::string>());
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
        m_console->Print("                   __  __\n");
        for(auto i = 0; i < (m_console->GetSize().x / 2) - 14; ++i) { m_console->Print(" "); }
        m_console->Print("  _____  __  __   / / / /\n");
        for(auto i = 0; i < (m_console->GetSize().x / 2) - 14; ++i) { m_console->Print(" "); }
        m_console->Print(" / _  /  | |/ /  / / / /\n");
        for(auto i = 0; i < (m_console->GetSize().x / 2) - 14; ++i) { m_console->Print(" "); }
        m_console->Print("/_//_/   |___/  /_/ /_/\n");

        m_console->Endl();
        m_console->Endl();
    }
};

auto main(int argc, char** argv) -> int {
    std::shared_ptr<nvll::Console> console = std::make_shared<nvll::Console>();
    std::shared_ptr<nvll::App> app = std::make_shared<nvll::App>(console.get());
    return app->Init();
}