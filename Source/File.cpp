#include "File.hpp"

namespace nvll {
    namespace file {
        void Create(std::string_view filename) {
            std::ofstream file(filename.data());

            if(file.is_open()) {
                file << "nvll";
                file.close();
            }
        }

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