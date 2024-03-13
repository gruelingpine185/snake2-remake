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
}
