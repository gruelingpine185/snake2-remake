#ifndef S2_ARRAY_H
#define S2_ARRAY_H


#include <cstddef>
#include <iterator>


namespace s2 {
    template <typename T, std::size_t N>
    class array;


    template <typename T, std::size_t N>
    class array {
    public:
        using value_type = T;
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = value_type*;
        using const_pointer = const pointer;
        using size_type = std::size_t;
    };
}

#endif // S2_ARRAY_H
