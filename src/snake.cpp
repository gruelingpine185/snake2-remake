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
    static constexpr s2::pos<T> scale_to_grid(const s2::size<T>& _size,
                                              const s2::pos<T>& _pos) {
        return s2::pos<T>(_pos.x() * _size.w(), _pos.y() * _size.h());
    }

    snake::snake(const s2::size<float>& _size,
                 const s2::pos<float>& _pos,
                 const s2::dir _dir) noexcept:
        _body{_pos}, _size(_size), _dir(_dir),
        _len(3) {}

    snake::~snake() noexcept {}

    void snake::handle_events(const SDL_Event& _event) noexcept {
        if(_event.type != SDL_EVENT_KEY_DOWN) return;

        switch(_event.key.keysym.sym) {
            case SDLK_UP:
                if(on_axis(s2::axis::y, this->_dir)) break;

                this->_dir = s2::dir::up;
                break;
            case SDLK_DOWN:
                if(on_axis(s2::axis::y, this->_dir)) break;

                this->_dir = s2::dir::down;
               break;
            case SDLK_LEFT:
                if(on_axis(s2::axis::x, this->_dir)) break;

                this->_dir = s2::dir::left;            
                break;
            case SDLK_RIGHT:
                if(on_axis(s2::axis::x, this->_dir)) break;

                this->_dir = s2::dir::right;
                break;
        }
    }

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
