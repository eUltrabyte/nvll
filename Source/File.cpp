#include "File.hpp"

namespace nvll {
    namespace file {
        void Create(std::ofstream& file, std::string_view filename) {
            file.open(filename.data());
        }

        void Add(std::ofstream& file, std::string_view line) {
            if(file.is_open()) {
                file << line;
            }
        }

        std::string Open(std::string_view filename) {
            std::string data;
            std::ifstream file(filename.data());

            if(file.is_open()) {
                std::string line;

                while(std::getline(file, line)) {
                    std::string type = line.substr(0, 3);

                    if(type == "[ ]") {
                        line.replace(0, 3, "\t&7[ ]&r");
                    } else if(type == "[-]") {
                        line.replace(0, 3, "\t&7[&c-&7]&r");
                    } else if(type == "[x]") {
                        line.replace(0, 3, "\t&7[&ax&7]&r");
                    }

                    data += line + '\n';
                }

                file.close();
            }

            return data;
        }
    };
};