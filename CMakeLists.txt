cmake_minimum_required(VERSION 3.17)
project(nvll)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(COPY Resources/ DESTINATION Resources/)
set(ICON "${CMAKE_CURRENT_SOURCE_DIR}/Resources/Icon.rc")

add_executable(${PROJECT_NAME}
    Source/Platform.hpp
    Source/Platform.cpp
    Source/Console.hpp
    Source/Console.cpp
    Source/Command.hpp
    Source/Command.cpp
    Source/File.hpp
    Source/File.cpp
    Source/nvll.hpp
    Source/nvll.cpp
    ${ICON}
)

target_precompile_headers(${PROJECT_NAME} PUBLIC Source/nvllpch.hpp Source/nvllpch.cpp)
