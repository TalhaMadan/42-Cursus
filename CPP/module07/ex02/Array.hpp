#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
    private:
        T* array;
        unsigned int size_;
    public:
        Array() : array(NULL), size_(0) {}

        Array(unsigned int n) : array(new T[n]), size_(n) {}

        Array(const Array& copy) : array(NULL), size_(0) {
            *this = copy;
        }

        ~Array() {
            delete[] array;
        }

        Array& operator=(const Array& other) {
            if (this != &other) {
                if (array)
                    delete[] array;

                size_ = other.size_;
                array = new T[size_];

                for (unsigned int i = 0; i < size_; ++i) {
                    array[i] = other.array[i];
                }
            }
            return *this;
        }
        T& operator[] (unsigned int i) {
            if (i >= size_)
                throw std::out_of_range("Index is out of bounds");
            else
                return array[i];
        }
        unsigned int Getsize() const {
            return size_;
        }
};

#endif

