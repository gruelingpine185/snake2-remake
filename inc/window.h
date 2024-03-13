#ifndef S2_WINDOW_H
#define S2_WINDOW_H


#include <string>

#include "utils/size.h"


struct SDL_Window;
union SDL_Event;


namespace s2 {
    class window;


    class window {
    public:
        window(const std::string& _title,
               const s2::size<int>& _size,
               const bool _resizable = false) noexcept;
        window(const window& _win) noexcept = delete;
        window() noexcept;
        ~window() noexcept;
        window& operator= (const window& _win) noexcept = delete;
    private:
        SDL_Window* _window;
        std::string _title;
        s2::size<int> _size;
        bool _is_resizable;
        bool _should_close;
    };
}

#endif // S2_WINDOW_H
