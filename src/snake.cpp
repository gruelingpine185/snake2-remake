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
    static constexpr s2::pos<T> scale_to_screen(const s2::size<T>& _size,
                                                const s2::pos<T>& _pos) {
        return s2::pos<T>(_pos.x() * _size.w(), _pos.y() * _size.h());
    }

    snake::snake(const s2::size<float>& _size,
                 const s2::pos<float>& _pos,
                 const std::uint32_t _len,
                 const float _vel) noexcept:
        _anchors{_pos, {_pos.x(), _pos.y() + 3}, {_pos.x() + 3, _pos.y() + 3},
            {_pos.x() + 3, _pos.y() + 8}},
        _size(_size), _len(_len), _vel(_vel) {}

    snake::~snake() noexcept {}

    void snake::handle_events(const SDL_Events& _events) noexcept {}

    void snake::update(std::uint32_t _ticks) noexcept {}

    bool snake::render(SDL_Renderer* _renderer) noexcept {
        if(SDL_SetRenderDrawColor(_renderer, 0xff, 0xc0, 0x00, 0xff) < 0) {
            return false;
        }

        SDL_FRect segment;
        for(std::size_t i = 0; i < this->_anchors.cap() - 1; i++) {
            s2::pos<float> curr_pos = scale_to_screen(this->_size,
                                                      this->_anchors[i]);
            s2::pos<float> next_pos = scale_to_screen(this->_size,
                                                      this->_anchors[i + 1]);
            s2::size size = dist_between(curr_pos, next_pos);
            segment.x = curr_pos.x();
            segment.y = curr_pos.y();
            if(curr_pos.y() == next_pos.y()) {
                segment.h = this->_size.h();
                segment.w = size.w();
            } else {
                segment.h = size.h();
                segment.w = this->_size.w();
            }

            if(SDL_RenderFillRect(_renderer, &segment) == -1) return false;
        }
    }
}
