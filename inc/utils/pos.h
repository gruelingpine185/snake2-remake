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

        constexpr pos& operator= (const pos<T>& _pos) noexcept {
            if(*this == _pos) return *this;

            this->_x = _pos.x();
            this->_x = _pos.x();
            return *this;
        }
    private:
        T _x;
        T _y;
    };
}

#endif // S2_SIZE_H
