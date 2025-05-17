#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
    private :
        int fixed_int;
        const static int cons_bit = 8;

    public :
        Fixed();
        ~Fixed();
        Fixed(const int fixed);
        Fixed(const float fixed);
        Fixed(const Fixed& fixed);
    

        Fixed& operator=(const Fixed& fixed);
        bool operator<(const Fixed& fixed);
        bool operator<=(const Fixed& fixed);
        bool operator>(const Fixed& fixed);
        bool operator>=(const Fixed& fixed);
        bool operator==(const Fixed& fixed);
        bool operator!=(const Fixed& fixed);

        Fixed operator+(const Fixed& fixed);
        Fixed operator-(const Fixed& fixed);
        Fixed operator*(const Fixed& fixed);
        Fixed operator/(const Fixed& fixed);

        Fixed operator++(int);
        Fixed& operator++();

        Fixed operator--(int);
        Fixed& operator--();

        static Fixed& Min(Fixed& fixed1, Fixed& Fixed2);
        static const Fixed& Min(const Fixed& fixed1, const Fixed& Fixed2);
        static Fixed& Max(Fixed& fixed1, Fixed& fixed2);
        static const Fixed& Max(const Fixed& fixed1, const Fixed& Fixed2);

        int     getRawBits() const;
        void    setRawBits(int const raw);

        float   toFloat() const;
        int     toInt() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif