#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter (T *ptr, size_t lenght, void (*func)(T & element)) {
    for (size_t i = 0; i < lenght; i++)
        func(ptr[i]);
}

template <typename T>
void iter (T *ptr, size_t lenght, void (*func)(const T & element)) {
    for (size_t i = 0; i < lenght; i++)
        func(ptr[i]);
}

#endif