#include "Regex.hpp"
class Polynomial
{
private:
    int coefficients[41];

public:
    Polynomial(void);
    Polynomial(const Polynomial &copy);
    ~Polynomial(void);
    Polynomial operator-();
    Polynomial operator+(const Polynomial &p);
    Polynomial &operator+=(const Polynomial &p);
    Polynomial operator-(const Polynomial &p);
    Polynomial &operator-=(const Polynomial &p);
    Polynomial operator*(const Polynomial &p);
    Polynomial &operator*=(const Polynomial &p);
    long long operator()(int x);
    int operator[](int exp);
    bool operator==(const Polynomial &p);
    bool operator!=(const Polynomial &p);
    bool operator<=(const Polynomial &p);
    bool operator>=(const Polynomial &p);
    bool operator>(const Polynomial &p);
    bool operator<(const Polynomial &p);
    friend std::istream &operator>>(std::istream &in, Polynomial &p);
    friend std::ostream &operator<<(std::ostream &out, Polynomial &p);
};
