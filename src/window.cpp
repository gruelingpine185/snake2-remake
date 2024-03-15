#include <cstddef>

#include <SDL3/SDL_init.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_events.h>

#include "window.h"


namespace s2 {
    static constexpr std::uint32_t enabled_sdl_flags = SDL_INIT_VIDEO;


    window::window(const std::string& _title,
                   const s2::size<int>& _size,
                   const bool _resizable) noexcept:
        _window(nullptr), _renderer(nullptr), _title(_title),
        _size(_size), _is_resizable(_resizable), _should_close(false) {}

    window::window() noexcept:
        _window(nullptr), _renderer(nullptr), _title{},
        _size(800, 600), _is_resizable(false), _should_close(false) {}

    window::~window() noexcept {}

    bool window::create(const std::string& _title,
                        const s2::size<int>& _size,
                        const bool _resizable) noexcept {
        this->_title = _title;
        this->_size = _size;
        this->_is_resizable = _resizable;
        return this->create();
    }

    bool window::create() noexcept {
        if(SDL_InitSubSystem(enabled_sdl_flags) < 0) return false;

        this->_window = SDL_CreateWindow(_title.c_str(),
                                         this->_size.w(),
                                         this->_size.h(),
                                         (this->_is_resizable)?
                                            SDL_WINDOW_RESIZABLE:
                                            0);

        if(!this->_window) return false;

        this->_renderer = SDL_CreateRenderer(this->_window,
                                             nullptr,
                                             SDL_RENDERER_PRESENTVSYNC);
        if(!this->_renderer) return false;

        return this->clear_screen();
    }

    bool window::show() noexcept {
        return (SDL_ShowWindow(this->_window) == 0);
    }

    bool window::hide() noexcept {
        return (SDL_HideWindow(this->_window) == 0);
    }

    bool window::clear_screen() noexcept {
        if(SDL_SetRenderDrawColor(this->_renderer, 0x24, 0x24, 0x24, 0xff) < 0) {
            return false;
        };

        return (SDL_RenderClear(this->_renderer) < 0);
    }

    bool window::render() noexcept {
        return (SDL_RenderPresent(this->_renderer) < 0);
    }

    bool window::should_close() noexcept {
        return this->_should_close;
    }

    void window::handle_events(const SDL_Event& _event) noexcept {
        if(_event.type == SDL_EVENT_QUIT) this->_should_close = true;
    }

    std::string& window::title() noexcept {
        return this->_title;
    }

    const std::string& window::title() const noexcept {
        return this->_title;
    }

    s2::size<int>& window::size() noexcept {
        return this->_size;
    }

    const s2::size<int>& window::size() const noexcept {
        return this->_size;
    }
}
