#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
    private :
        int fixed_int;
        const static int cons_bit = 8;

    public :
        Fixed();
        Fixed(const int fixed);
        Fixed(const float fixed);
        Fixed(const Fixed& fixed);
        Fixed& operator=(const Fixed& fixed);
        ~Fixed();

        int     getRawBits() const;
        void    setRawBits(int const raw);

        float   toFloat() const;
        int     toInt() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif