#include "Fixed.hpp"

Fixed::Fixed() {
    this->fixed_int = 0;
    std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(const int fixed) {
    this->fixed_int = fixed * pow(2, this->cons_bit);
    std::cout << "İnt constructor called." << std::endl;
}

Fixed::Fixed(const float fixed) {
    this->fixed_int = roundf(fixed * pow(2, this->cons_bit));
    std::cout << "Float constructor called." << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed){
    this->fixed_int = fixed.fixed_int;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed:: operator=(const Fixed& fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &fixed)
        return *this;
    this->fixed_int = fixed.fixed_int;
    return *this;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixed_int;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->fixed_int = raw;
}

int Fixed::toInt() const {
    return ((this->fixed_int / pow(2, this->cons_bit)));
}

float Fixed::toFloat() const {
    return ((float)this->fixed_int / pow(2, this->cons_bit));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}