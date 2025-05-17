#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int value) {
    typename T::iterator i = std::find(container.begin(), container.end(), value);
    if (i == container.end())
        throw std::exception();
    return i;
}

#endif