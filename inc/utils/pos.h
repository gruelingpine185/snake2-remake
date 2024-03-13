#ifndef S2_SIZE_H
#define S2_SIZE_H


#include <type_traits>


namespace s2 {
    template <
        typename T,
        typename = typename std::enable_if_t<std::is_arithmetic_v<T>>
    >
    class pos;


    template <typename T>
    class pos<T> {
    public:
        using value_type = T;
    public:
        constexpr pos(const value_type _w, const value_type _h) noexcept:
            _x(_w), _y(_h) {}

        constexpr pos(const value_type _n) noexcept:
            _x(_n), _y(_n) {}

        constexpr pos(const pos& _size) noexcept:
            _x(_size._w), _y(_size._h) {}

        constexpr pos() noexcept {}

        ~pos() noexcept {}

        value_type x() noexcept {
            return this->_x;
        }

        const value_type x() const noexcept {
            return this->_x;
        }

        value_type y() noexcept {
            return this->_y;
        }

        const value_type y() const noexcept {
            return this->_y;
        }

        constexpr pos& operator= (const pos<T>& _pos) noexcept {
            if(*this == _pos) return *this;

            this->_x = _pos.x();
            this->_x = _pos.x();
            return *this;
        }

        constexpr pos& operator+= (const pos<T>& _pos) noexcept {
            this->_x += _pos._x;
            this->_y += _pos._y;
            return *this;
        }

        constexpr pos& operator-= (const pos<T>& _pos) noexcept {
            *this += -_pos;
            return *this;
        }
    private:
        T _x;
        T _y;
    };


    template <typename T>
    constexpr bool operator== (const pos<T>& _l, const pos<T>& _r) {
        return ((_l.x() == _r.x()) && (_l.y() == _r.y()));
    }

    template <typename T>
    constexpr bool operator!= (const pos<T>& _l, const pos<T>& _r) {
        return (!(_l == _r));
    }

    template <
        typename T,
        typename = typename std::enable_if_t<std::is_arithmetic_v<T>>
    >
    constexpr pos<T> operator* (const pos<T>& _l, const pos<T>& _r) {
        return ((_l.x() * _r.x()), (_l.y() * _r.y()));
    }

    template <
        typename T,
        typename = typename std::enable_if_t<std::is_arithmetic_v<T>>
    >
    constexpr pos<T> operator/ (const pos<T>& _l, const pos<T>& _r) {
        return ((_l.x() / _r.x()), (_l.y() / _r.y()));
    }

    template <
        typename T,
        typename = typename std::enable_if_t<std::is_arithmetic_v<T>>
    >
    constexpr pos<T> operator+ (const pos<T>& _l, const pos<T>& _r) {
        return ((_l.x() + _r.x()), (_l.y() * _r.y()));
    }

    template <
        typename T,
        typename = typename std::enable_if_t<std::is_arithmetic_v<T>>
    >
    constexpr pos<T> operator- (const pos<T>& _l, const pos<T>& _r) {
        return ((_l.x() - _r.x()), (_l.y() - _r.y()));
    }
}

#endif // S2_SIZE_H
