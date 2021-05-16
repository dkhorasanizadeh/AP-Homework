/*
--------------------------------------------------
Name    : DateTime
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 05/May/2021
--------------------------------------------------
*/
#ifndef DATE_TIME_HPP_
#define DATE_TIME_HPP_
#include "Date.hpp"
#include "Time.hpp"
class DateTime : public Date, public Time
{
public:
    DateTime(void) : Date(){};
    DateTime(int y) : Date(y){};
    DateTime(int y, int m) : Date(y, m){};
    DateTime(int y, int m, int d) : Date(y, m, d){};
    DateTime(int y, int m, int d, int h) : Date(y, m, d), Time(h){};
    DateTime(int y, int m, int d, int h, int minute) : Date(y, m, d), Time(h, minute){};
    friend std::istream &operator>>(std::istream &in, DateTime &dt);
    friend std::ostream &operator<<(std::ostream &out, DateTime &dt);
    bool operator<(const DateTime &dt);
    bool operator>(const DateTime &dt);
    bool operator==(const DateTime &dt);
    bool operator<=(const DateTime &dt);
    bool operator>=(const DateTime &dt);
    DateTime operator+(const DateTime &dt);
    operator std::string();
};
#endif