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

            iterator& operator= (const iterator& _iter) {
                if(*this == _iter) return *this;

                this->_ptr = _iter._ptr;
                return *this;
            }

            constexpr bool operator== (const iterator& _iter) const noexcept {
                return (this->_ptr == _iter._ptr);
            }

            constexpr bool operator!= (const iterator& _iter) const noexcept {
                return (!(this->_ptr == _iter));
            }

            iterator& operator++ () {
                this->_ptr++;
                return *this;
            }

            iterator& operator++ (int _unused) {
                static_cast<void>(_unused);
                iterator iter = *this;
                ++(*this);
                return iter;
            }

            iterator& operator-- () {
                this->_ptr--;
                return *this;
            }

            iterator& operator-- (int _unused) {
                static_cast<void>(_unused);
                iterator iter = *this;
                --(*this);
                return iter;
            }

            iterator operator+ (const size_type _offset) const {
                iterator iter = *this;
                iter._ptr += _offset;
                return iter;
            }

            iterator operator- (const size_type _offset) const {
                iterator iter = *this;
                iter._ptr -= _offset;
                return iter;
            }

            iterator& operator+= (const size_type _offset) {
                this->_ptr += _offset;
                return *this;
            }

            iterator& operator-= (const size_type _offset) {
                this->_ptr -= _offset;
                return *this;
            }

            reference operator* () const {
                return *this->_ptr;
            }

            pointer operator-> () const {
                return this->_ptr;
            }

            reference operator[] (const size_type _offset) const {
                return this->_data[_offset];
            }
        private:
            pointer _ptr;
        };
    };
}

#endif // S2_ARRAY_H
