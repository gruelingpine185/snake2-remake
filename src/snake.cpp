#include <iostream>

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
        return s2::size<T>((_r.x() - _l.x()), (_r.y() - _l.y()));
    }

    template <
        typename T,
        typename = typename std::enable_if_t<std::is_arithmetic_v<T>>
    >
    static constexpr bool axis_from_dist(const s2::size<T>& _size,
                                         const s2::size<T>& _dist) {
        return (_dist.w() >= _size.w());
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
        _anchors{_pos, {_pos.x(), _pos.y() + 3}, {_pos.x() + 3, _pos.y() + 3}}, _size(_size), _len(_len),
        _vel(_vel) {}

    snake::~snake() noexcept {}

    void snake::handle_events(const SDL_Events& _events) noexcept {}

    void snake::update(std::uint32_t _ticks) noexcept {}

    bool snake::render(SDL_Renderer* _renderer) noexcept {
        if(SDL_SetRenderDrawColor(_renderer, 0xff, 0xff, 0x00, 0xff) < 0) {
            return false;
        }

        s2::pos<float> pos_1;
        s2::pos<float> pos_2;
        SDL_FRect rect;
        auto prev = this->_anchors.begin();
        for(auto a: this->_anchors) {
            std::cout << a.x() << ", " << a.y() << std::endl;
        }

        std::cout << std::endl;
#if 0
        for(auto iter = prev + 1; iter != this->_anchors.cap_end(); iter++) {
            pos_1 = scale_to_screen(this->_size, *prev);
            pos_2 = scale_to_screen(this->_size, *iter);
            s2::size<float> dist = dist_between(pos_1, pos_2);
            if(axis_from_dist(this->_size, dist)) {
                rect.w = dist.w();
                rect.h = this->_size.h();
            } else {
                rect.w = this->_size.w();
                rect.h = dist.h();
            }

            rect.x = pos_1.x();
            rect.y = pos_1.y();
            SDL_RenderFillRect(_renderer, &rect);
            std::cout << rect.x/this->_size.w() << " " << rect.y/this->_size.h() << std::endl;
            prev++;
        }
#endif
        return true;
    }
}
