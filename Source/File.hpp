#pragma once
#ifndef NVLL_FILE_HEADER
#define NVLL_FILE_HEADER

#include "nvllpch.hpp"

namespace nvll {
    namespace file {
        extern void Create(std::ofstream& file, std::string_view filename);
        extern void Add(std::ofstream& file, std::string_view line);
        extern std::string Open(std::string_view filename);
    };
};

#endif