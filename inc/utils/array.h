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
    public:
        class iterator {
        public:
            using reference = array::reference;
            using pointer = array::pointer;
            using size_type = array::size_type;
            using difference_type = std::ptrdiff_t;
            using iterator_category = std::random_access_iterator_tag;
        public:
            iterator(const pointer _ptr):
                _ptr(_ptr) {}

            iterator(const iterator& _iter):
                _ptr(_iter._ptr) {}

            iterator() noexcept:
                _ptr(nullptr) {}

            ~iterator() noexcept {}
        private:
            pointer _ptr;
        };
    };
}

#endif // S2_ARRAY_H
