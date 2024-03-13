#ifndef S2_SIZE_H
#define S2_SIZE_H


#include <type_traits>


namespace s2 {
    template <
        typename T,
        typename = typename std::enable_if_t<std::is_arithmetic_v<T>>
    >
    class size;


    template <typename T>
    class size<T> {
    public:
        using value_type = T;
    public:
        constexpr size(const value_type _w, const value_type _h) noexcept:
            _w(_w), _h(_h) {}

        constexpr size(const value_type _n) noexcept:
            _w(_n), _h(_n) {}

        constexpr size(const size& _size) noexcept:
            _w(_size._w), _h(_size._h) {}

        constexpr size() noexcept {}

        ~size() noexcept {}

        value_type w() noexcept {
            return this->_w;
        }

        const value_type w() const noexcept {
            return this->_w;
        }

        value_type h() noexcept {
            return this->_h;
        }

        const value_type h() const noexcept {
            return this->_h;
        }

        constexpr size& operator= (const size<T>& _size) noexcept {
            if(*this == _size) return *this;

            this->_w = _size.w();
            this->_h = _size.h();
            return *this;
        }

        constexpr size& operator+= (const size<T>& _size) noexcept {
            this->_w += _size._w;
            this->_h += _size._h;
            return *this;
        }

        constexpr size& operator-= (const size<T>& _size) noexcept {
            *this += -_size;
            return *this;
        }

        constexpr size& operator*= (const size<T>& _size) noexcept {
            this->_w *= _size._h;
            this->_h *= _size._h;
            return *this;
        }

        constexpr size& operator/= (const size<T>& _size) noexcept {
            this->_w /= _size._w;
            this->_h /= _size._h;
            return *this;
        }
    private:
        T _w;
        T _h;
    };


    template <typename T>
    constexpr bool operator== (const size<T>& _l, const size<T>& _r) {
        return ((_l.w() == _r.w()) && (_l.h() == _r.h()));
    }

    template <typename T>
    constexpr bool operator!= (const size<T>& _l, const size<T>& _r) {
        return (!(_l == _r));
    }

    template <
        typename T,
        typename = typename std::enable_if_t<std::is_arithmetic_v<T>>
    >
    constexpr size<T> operator* (const size<T>& _l, const size<T>& _r) {
        return ((_l.w() * _r.w()), (_l.h() * _r.w()));
    }

    template <
        typename T,
        typename = typename std::enable_if_t<std::is_arithmetic_v<T>>
    >
    constexpr size<T> operator/ (const size<T>& _l, const size<T>& _r) {
        return ((_l.w() / _r.w()), (_l.h() / _r.w()));
    }

    template <
        typename T,
        typename = typename std::enable_if_t<std::is_arithmetic_v<T>>
    >
    constexpr size<T> operator+ (const size<T>& _l, const size<T>& _r) {
        return ((_l.w() + _r.w()), (_l.h() * _r.w()));
    }

    template <
        typename T,
        typename = typename std::enable_if_t<std::is_arithmetic_v<T>>
    >
    constexpr size<T> operator- (const size<T>& _l, const size<T>& _r) {
        return ((_l.w() - _r.w()), (_l.h() - _r.w()));
    }
}

#endif // S2_SIZE_H
