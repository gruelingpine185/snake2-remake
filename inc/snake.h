#ifndef S2_SNAKE_H
#define S2_SNAKE_H


#include <cstdint>
#include <vector>

#include "utils/size.h"
#include "utils/pos.h"


struct SDL_Renderer;
union SDL_Event;


namespace s2 {
    class snake;
    enum class dir;


    class snake {
    public:
        snake(const s2::size<float>& _size,
              const s2::pos<float>& _pos,
              const s2::dir _dir,
              const std::uint32_t _len = 4) noexcept;
        ~snake() noexcept;

        void handle_events(const SDL_Event& _event) noexcept;
        void update(const std::uint32_t _ticks) noexcept;
        bool render(SDL_Renderer* _renderer) noexcept;
    private:
        std::vector<s2::pos<float>> _body;
        s2::size<float> _size;
        dir _dir;
        std::uint32_t _len;
    };
}

#endif // S2_SNAKE_H

