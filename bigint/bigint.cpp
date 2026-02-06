#include "bigint.hpp"

// constructores y destructor
bigint::bigint() : digits("0") {
    std::cout << "Default constructor digits = " << digits << std::endl;
}

bigint::bigint(unsigned int n) {
    std::stringstream ss;
    ss << n;
    digits = ss.str();
    std::cout << "int constructor digits = " << digits << std::endl;
}

bigint::bigint(const std::string& str) {
    if (str.empty())
        throw std::invalid_argument("Invalid input\n");
    std::string::const_iterator start = str.begin();
    std::string::const_iterator end = str.end();
    while (start != end) {
        if (!std::isdigit(*start))
            throw std::invalid_argument("Invalid input\n");
        start++;
    }
    digits = str;
    remove_leading_zeros();
    std::cout << "string constructor digits = " << digits << std::endl;
}

void bigint::remove_leading_zeros() {
    std::string::size_type pos = digits.find_first_not_of('0');
    if (pos == std::string::npos)
        digits = "0";
    else
        digits.erase(0, pos);
}

bigint::bigint(const bigint& other) : digits(other.digits) {
    std::cout << "constructor de copia digits = " << digits << std::endl;
}

const bigint& bigint::operator=(const bigint& other) {
    if (this != &other) {
        digits = other.digits;
    }
    return *this;
}

bigint::~bigint() {}


// operador <<
const std::string bigint::getDigits() const {
    return digits;
}
std::ostream& operator<<(std::ostream& os, const bigint& bigint) {
    os << bigint.getDigits();
    return os;
}


// operador de suma
bigint bigint::operator+(const bigint& other) const {
    std::string result;
    
    int i = digits.size() - 1;
    int j = other.digits.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry > 0) {
        int num = (i >= 0) ? digits[i--] - '0' : 0;
        int other_num = (j >= 0) ? other.digits[j--] - '0' : 0;
        int sum = num + other_num + carry;
        carry = sum / 10;
        result.push_back((sum%10) + '0');
    }
    std::reverse(result.begin(), result.end());
    return bigint(result);
}
bigint& bigint::operator+=(const bigint& other) {
    *this = *this + other;
    return *this;
}

// operadores de aumento
bigint& bigint::operator++() {
    *this += bigint(1);
    return (*this);
}
bigint bigint::operator++(int) {
    bigint temp(*this);
    *this += bigint(1);
    return (temp);
}

// operadores de shift
bigint bigint::operator<<(int num) const {
    bigint temp(*this);
    temp <<= num;
    return temp;
}
bigint& bigint::operator<<=(int num) {
    digits += std::string(num, '0');
    return *this;
}
bigint& bigint::operator>>=(const bigint& other) {
    std::stringstream ss(other.digits);
    int shift;
    ss >> shift;
    return *this >>= shift;
}
bigint& bigint::operator>>=(int num) {
    if ((size_t )num >= digits.size())
        digits = "0";
    else
        digits.erase(digits.size() - num);
    return *this;
}
bigint& bigint::operator<<=(const bigint& other) {
    std::stringstream ss(other.digits);
    int shift;
    ss >> shift;
    return *this <<= shift;
}

// operadores comparacion
bool bigint::operator<(const bigint& other) const {
    return other > *this;
}
bool bigint::operator>(const bigint& other) const {
    if (digits.size() != other.digits.size()) {
        return digits.size() > other.digits.size();
    }
    return digits > other.digits;
}
bool bigint::operator==(const bigint& other) const {
    return (digits == other.digits);
}
bool bigint::operator!=(const bigint& other) const {
    return !(digits == other.digits);
}
bool bigint::operator<=(const bigint& other) const {
    return !(*this > other);
}
bool bigint::operator>=(const bigint& other) const {
    return !(*this < other);
}

// 

