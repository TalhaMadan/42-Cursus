#include "Span.hpp"

Span::~Span() {}

Span::Span() {
    this->N = 0; 
}

Span::Span(unsigned int N) {
    this->N = N;
}

Span::Span(const Span &copy) : N(copy.N), vec(copy.vec) {}

Span& Span::operator=(const Span &copy) {
    if (this != &copy) {
        this->N = copy.N;
        this->vec = copy.vec;
    }
    return *this;
}

int Span::shortestSpan() {
    if (this->vec.size() <= 1)
        throw EmptyException();
    std::sort(vec.begin(), vec.end());
    int min = vec[1] - vec[0];
    for (size_t i = 2; i < vec.size(); ++i) {
        int isShortest = vec[i] - vec[i - 1];
        if (isShortest < min)
            min = isShortest;
    }
    return min;
}

int Span::longestSpan() {
    if (this->vec.size() <= 1)
        throw EmptyException();
    std::sort(vec.begin(), vec.end());
    return vec.back() - vec.front();
}

void Span::addNumber(int num) {
    if (this->vec.size() >= this->N)
        throw OverCapacityException();
    this->vec.push_back(num);
}

void Span::addNumber (std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    while (begin != end) {
        if (this->vec.size() > this->N)
            throw OverCapacityException();
        this->vec.push_back(*begin++);
    }

}

const char *Span::OverCapacityException::what() const throw() {
    return ("Span is full: Cannot add more numbers!");
}

const char *Span::EmptyException::what() const throw() {
    return ("Not enough numbers to calculate the span. At least two numbers are required!");
}