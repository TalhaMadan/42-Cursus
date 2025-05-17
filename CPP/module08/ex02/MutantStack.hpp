#ifndef MUTANT_STACK
# define MUTANT_STACK

#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack() {}

        MutantStack(const MutantStack<T>& copy) : std::stack<T>(copy) {}

        MutantStack& operator=(const MutantStack<T>& copy) {
            if (this != &copy) {
                std::stack<T>::operator=(copy);
            }
            return *this;
        }

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        iterator begin() { return std::stack<T>::c.begin(); }
        iterator end() { return std::stack<T>::c.end(); }
        const_iterator begin() const { return std::stack<T>::c.begin(); }
        const_iterator end() const { return std::stack<T>::c.end(); }

        ~MutantStack() {}
};

#endif