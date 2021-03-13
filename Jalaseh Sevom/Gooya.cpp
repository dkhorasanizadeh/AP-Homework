/*
--------------------------------------------------
Name    : Gooya
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 08/Mar/2021
--------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
class Rational
{
public:
    Rational(void);
    Rational(int numerator, int denominator);
    int getNumerator(void);
    int getDenominator(void);
    void setNumerator(int numerator);
    void setDenominator(int denominator);
    void setRational(int numerator, int denominator);
    void setRational(string rational);
    Rational add(Rational r);
    Rational subtract(Rational r);
    Rational multiply(Rational r);

private:
    int numerator;
    int denominator;
};
Rational::Rational(void)
{
    setNumerator(0);
    setDenominator(1);
    cout << "Class Created" << endl;
}
Rational::Rational(int numerator, int denominator)
{
    if (denominator != 0)
    {
        setNumerator(numerator);
        setDenominator(denominator);
        cout << "Class created." << endl;
    }
    else
    {
        setNumerator(numerator);
        setDenominator(1);
        cout << "Error!" << endl
             << "Denominator can't be zero." << endl
             << "Class created with 1 as denominator." << endl;
    }
}
int Rational::getNumerator(void)
{
    return numerator;
}
int Rational::getDenominator(void)
{
    return denominator;
}
void Rational::setNumerator(int n)
{
    numerator = n;
}
void Rational::setDenominator(int d)
{
    if (d != 0)
    {
        denominator = d;
    }
    else
    {
        cout << "Error!" << endl
             << "Denominator can't be zero, it didn't chnage." << endl;
    }
}
void Rational::setRational(int numerator, int denominator)
{
    if (denominator != 0)
    {
        setNumerator(numerator);
        setDenominator(denominator);
    }
    else
    {
        cout << "Error!" << endl
             << "Denominator can't be zero." << endl
             << "Nothing changed.";
    }
}
void Rational::setRational(string s)
{
    char *s_CString = (char *)s.c_str();
    char *token = strtok(s_CString, "/");
    int n, d;
    n = stoi(token);
    token = strtok(NULL, "/");
    d = stoi(token);
    setRational(n, d);
}
Rational Rational::add(Rational r)
{
    int newNumerator = (numerator * r.denominator) + (denominator * r.numerator);
    int newDenominator = denominator * r.denominator;
    Rational newRational(newNumerator, newDenominator);
    return newRational;
}
Rational Rational::subtract(Rational r)
{
    int newNumerator = (numerator * r.denominator) + (-1 * denominator * r.numerator);
    int newDenominator = denominator * r.denominator;
    Rational newRational(newNumerator, newDenominator);
    return newRational;
}
Rational Rational::multiply(Rational r)
{
    int newNumerator = numerator * r.numerator;
    int newDenominator = denominator * r.denominator;
    Rational newRational(newNumerator, newDenominator);
    return newRational;
}
int main(void)
{
    return 0;
}