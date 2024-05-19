#include "nvll.hpp"

auto main(int argc, char** argv) -> int {
    std::shared_ptr<nvll::Console> console = std::make_shared<nvll::Console>();
    return console->Init();
}