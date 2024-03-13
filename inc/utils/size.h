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
    private:
        T _w;
        T _h;
    };
}

#endif // S2_SIZE_H
