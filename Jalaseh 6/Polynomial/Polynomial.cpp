#include "Polynomial.hpp"
#include <cmath>
Polynomial::Polynomial(void)
{
    for (int i = 0; i < 41; i++)
    {
        coefficients[i] = 0;
    }
}
Polynomial::Polynomial(const Polynomial &copy)
{
    for (int i = 0; i < 41; i++)
    {
        coefficients[i] = copy.coefficients[i];
    }
}
Polynomial::~Polynomial(void)
{
}
Polynomial Polynomial::operator-()
{
    Polynomial changedValue;
    for (int i = 0; i < 41; i++)
    {
        changedValue.coefficients[i] = -coefficients[i];
    }
    return changedValue;
}
Polynomial Polynomial::operator+(const Polynomial &p)
{
    Polynomial changedValue;
    for (int i = 0; i < 41; i++)
    {
        changedValue.coefficients[i] = coefficients[i] + p.coefficients[i];
    }
    return changedValue;
}
Polynomial &Polynomial::operator+=(const Polynomial &p)
{
    for (int i = 0; i < 41; i++)
    {
        coefficients[i] += p.coefficients[i];
    }
    return *this;
}
Polynomial Polynomial::operator-(const Polynomial &p)
{
    Polynomial changedValue;
    for (int i = 0; i < 41; i++)
    {
        changedValue.coefficients[i] = coefficients[i] - p.coefficients[i];
    }
    return changedValue;
}
Polynomial &Polynomial::operator-=(const Polynomial &p)
{
    for (int i = 0; i < 41; i++)
    {
        coefficients[i] -= p.coefficients[i];
    }
    return *this;
}
Polynomial Polynomial::operator*(const Polynomial &p)
{
    Polynomial changedValue;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            changedValue.coefficients[i + j] += coefficients[i] * p.coefficients[j];
        }
    }
    return changedValue;
}
Polynomial &Polynomial::operator*=(const Polynomial &p)
{
    Polynomial changedValue;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            changedValue.coefficients[i + j] += coefficients[i] * p.coefficients[j];
        }
    }
    for (int i = 0; i < 41; i++)
    {
        coefficients[i] = changedValue.coefficients[i];
    }
    return *this;
}
long long Polynomial::operator()(int x)
{
    long long y = 0;
    for (int i = 0; i < 41; i++)
    {
        y += coefficients[i] * (long long)std::pow(x, i);
    }
    return y;
}
int Polynomial::operator[](int exp)
{
    return coefficients[exp];
}
bool Polynomial::operator==(const Polynomial &p)
{
    for (int i = 0; i < 41; i++)
    {
        if (coefficients[i] != p.coefficients[i])
        {
            return false;
        }
    }
    return true;
}
bool Polynomial::operator!=(const Polynomial &p)
{
    for (int i = 0; i < 41; i++)
    {
        if (coefficients[i] == p.coefficients[i])
        {
            return false;
        }
    }
    return true;
}
bool Polynomial::operator<=(const Polynomial &p)
{
    if (!(this->operator==(p)))
    {
        for (int i = 40; i >= 0; i--)
        {
            if (coefficients[i] < p.coefficients[i])
            {
                return true;
            }
            else if (coefficients[i] > p.coefficients[i])
            {
                return false;
            }
        }
    }
    return true;
}
bool Polynomial::operator>=(const Polynomial &p)
{
    if (!(this->operator==(p)))
    {
        for (int i = 41; i >= 0; i--)
        {
            if (coefficients[i] > p.coefficients[i])
            {
                return true;
            }
            else if (coefficients[i] < p.coefficients[i])
            {
                return false;
            }
        }
    }
    return true;
}
bool Polynomial::operator>(const Polynomial &p)
{
    for (int i = 40; i >= 0; i--)
    {
        if (coefficients[i] > p.coefficients[i])
        {
            return true;
        }
        else if (coefficients[i] < p.coefficients[i])
        {
            return false;
        }
    }
    return false;
}
bool Polynomial::operator<(const Polynomial &p)
{
    for (int i = 40; i >= 0; i--)
    {
        if (coefficients[i] < p.coefficients[i])
        {
            return true;
        }
        else if (coefficients[i] > p.coefficients[i])
        {
            return false;
        }
    }
    return false;
}
std::istream &operator>>(std::istream &in, Polynomial &p)
{
    std::string polynomial;
    in >> polynomial;
    splitPolynomial(polynomial, p.coefficients);
    return in;
}
std::ostream &operator<<(std::ostream &out, Polynomial &p)
{
    for (int i = 40; i > 1; i--)
    {
        if (p.coefficients[i] == 1)
        {
            out << "+x^" << i;
        }
        else if (p.coefficients[i] == -1)
        {
            out << "-x^" << i;
        }
        else if (p.coefficients[i] > 0)
        {
            out << "+" << p.coefficients[i] << "x^" << i;
        }
        else if (p.coefficients[i] < 0)
        {
            out << p.coefficients[i] << "x^" << i;
        }
    }
    if (p.coefficients[1] == 1)
    {
        out << "+x";
    }
    else if (p.coefficients[1] == -1)
    {
        out << "-x";
    }
    else if (p.coefficients[1] > 0)
    {
        out << "+" << p.coefficients[1] << "x";
    }
    else if (p.coefficients[1] < 0)
    {
        out << p.coefficients[1] << "x";
    }
    if (p.coefficients[0] > 0)
    {
        out << "+" << p.coefficients[0];
    }
    else if (p.coefficients[0] < 0)
    {
        out << p.coefficients[0];
    }
    out << std::endl;
    return out;
}
