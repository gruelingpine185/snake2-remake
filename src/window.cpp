#include "window.h"


namespace s2 {
    window::window(const std::string& _title,
                   const s2::size<int>& _size,
                   const bool _resizable) noexcept:
        _window(nullptr), _title(_title), _size(_size),
        _is_resizable(_resizable), _should_close(false) {}

    window::window() noexcept:
        _window(nullptr), _title{}, _size(800, 600),
        _is_resizable(false), _should_close(false) {}

    window::~window() noexcept {}

    bool window::should_close() noexcept {
        return this->_should_close;
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
