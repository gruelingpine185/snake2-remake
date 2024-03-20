#include <cmath>

#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_events.h>

#include "snake.h"


namespace s2 {
    template <
        typename T,
        typename = typename std::enable_if_t<std::is_arithmetic_v<T>>
    >
    static constexpr s2::size<T> dist_between(const s2::pos<T>& _l,
                                              const s2::pos<T>& _r) {
        return s2::size<T>(std::abs(_r.x() - _l.x()),
                           std::abs(_r.y() - _l.y()));
    }

    template <
        typename T,
        typename = typename std::enable_if_t<std::is_arithmetic_v<T>>
    >
    static constexpr s2::pos<T> scale_to_grid(const s2::size<T>& _size,
                                                const s2::pos<T>& _pos) {
        return s2::pos<T>(_pos.x() * _size.w(), _pos.y() * _size.h());
    }

    template <
        typename T,
        typename = typename std::enable_if_t<std::is_arithmetic_v<T>>
    >
    static bool snake_render_head(SDL_Renderer* _renderer,
                                  const s2::size<T>& _size,
                                  const s2::pos<T>& _pos) {
        if(SDL_SetRenderDrawColor(_renderer, 0xff, 0xff, 0xff, 0xff) < 0) {
            return false;
        }

        const s2::pos<float> head_pos = scale_to_grid(_size, _pos);
        const SDL_FRect segment = {
            head_pos.x(),
            head_pos.y(),
            _size.w(),
            _size.h()
        };

        return (SDL_RenderFillRect(_renderer, &segment) == 0);
    }


    snake::snake(const s2::size<float>& _size,
                 const s2::pos<float>& _pos,
                 const std::uint32_t _len,
                 const float _vel) noexcept:
        _anchors{_pos, {_pos.x(), _pos.y() + 3}, {_pos.x() + 3, _pos.y() + 3},
            {_pos.x() + 3, _pos.y() + 8}},
        _size(_size), _len(_len), _vel(_vel) {}

    snake::~snake() noexcept {}

    void snake::handle_events(const SDL_Event& _event) noexcept {

    void snake::update(const std::uint32_t _ticks) noexcept {
        if(_ticks % 16 != 0) return;
    }

    bool snake::render(SDL_Renderer* _renderer) noexcept {
        if(SDL_SetRenderDrawColor(_renderer, 0xff, 0xc0, 0x00, 0xff) < 0) {
            return false;
        }

        }

    }
}
