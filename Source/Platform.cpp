#include "Platform.hpp"

namespace nvll {
    namespace platform {
        void SetupANSI() {
            #ifdef NVLL_WINDOWS
                void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
                unsigned long mode = 0;
                GetConsoleMode(handle, &mode);
                mode |= 0x0004;
                SetConsoleMode(handle, mode);
            #endif
        }

        void ClearANSI() {
            std::cout << "\x1b[0m";
        }

        void TerminateANSI() {
            #ifdef NVLL_WINDOWS
                void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleMode(handle, 0x0004);
            #endif
        }
        
        vec2i GetConsoleSize() {
            #ifdef NVLL_WINDOWS
                CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo { };
                void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
                GetConsoleScreenBufferInfo(handle, &screenBufferInfo);
                return vec2i { screenBufferInfo.srWindow.Right - screenBufferInfo.srWindow.Left + 1, screenBufferInfo.srWindow.Bottom - screenBufferInfo.srWindow.Top + 1 };
            #else
                #ifdef TIOCGSIZE
                    struct ttysize size;
                    ioctl(STDOUT_FILENO, TIOCGSIZE, &size);
                    return vec2i { size.ts_cols, size.ts_lines };
                #else
                    struct winsize size;
                    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
                    return vec2i { size.ws_col, size.ws_row };
                #endif
            #endif

            return vec2i { 80, 25 };
        }

        void SetTitle() {
            std::cout << "\033]0;" << "nvll" << "\007";
        }
    };
};