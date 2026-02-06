#ifndef BIGINT_HPP
#define BIGINT_HPP
#include <string>
#include <iostream>
#include <sstream>
#include <exception>

class bigint {
    private:
        std::string digits;
    public:
        // constructores
        bigint();
        bigint(unsigned int);
        bigint(const std::string&);
        bigint(const bigint&);
        const bigint& operator=(const bigint&);
        void remove_leading_zeros();

        // operador de suma
        bigint operator+(const bigint&) const;
        bigint& operator+=(const bigint&);

        // operador de aumento
        bigint& operator++();
        bigint operator++(int);

        // operador de shift
        bigint operator<<(int) const;
        bigint& operator<<=(int);
        bigint& operator>>=(const bigint&);
        bigint& operator>>=(int);
        bigint& operator<<=(const bigint&);

        // operador de comparacion
        bool operator<(const bigint&) const;
        bool operator>(const bigint&) const;
        bool operator==(const bigint&) const;
        bool operator!=(const bigint&) const;
        bool operator<=(const bigint&) const;
        bool operator>=(const bigint&) const;

        // getter for non-member function
        const std::string getDigits() const;

        ~bigint();
};

// operador <<
std::ostream& operator<<(std::ostream&, const bigint&);

#endif