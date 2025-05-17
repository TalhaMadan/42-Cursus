#ifndef SPAN_HPP
# define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <vector>

class Span {
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &copy);
        Span& operator=(const Span &copy);

        void addNumber(int n);
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

        int shortestSpan();
        int longestSpan();

        ~Span();

        class OverCapacityException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class EmptyException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
    private:
        unsigned int N;
        std::vector<int> vec;
};

#endif