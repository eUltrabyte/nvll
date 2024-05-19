#include "File.hpp"

namespace nvll {
    namespace file {
        std::string Open(std::string_view filename) {
            std::string data;
            std::ifstream file(filename.data());

            if(file.is_open()) {
                std::string line;

                while(std::getline(file, line)) {
                    data += line + '\n';
                }

                file.close();
            }

            return data;
        }
    };
};