#ifndef S2_SNAKE_H
#define S2_SNAKE_H


#include <cstdint>

#include "utils/size.h"
#include "utils/pos.h"
#include "utils/array.h"


struct SDL_Renderer;
union SDL_Event;


namespace s2 {
    class snake;


    class snake {
    public:
        snake(const s2::size<float>& _size,
              const s2::pos<float>& _pos,
              const std::uint32_t _len = 3.0f,
              const float _vel = 1.0f) noexcept;
        ~snake() noexcept;

        void handle_events(const SDL_Event& _event) noexcept;
        void update(const std::uint32_t _ticks) noexcept;
        bool render(SDL_Renderer* _renderer) noexcept;
    private:
        s2::array<s2::pos<float>, 32> _anchors;
        s2::size<float> _size;
        std::uint32_t _len;
        float _vel;
    };
}

#endif // S2_SNAKE_H

