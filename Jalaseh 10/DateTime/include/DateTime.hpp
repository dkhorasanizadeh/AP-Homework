/*
--------------------------------------------------
Name    : DateTime
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 21/May/2021
--------------------------------------------------
*/
#ifndef DATE_TIME_HPP_
#define DATE_TIME_HPP_
#include <regex>
#include "Date.hpp"
#include "Time.hpp"
#include "Exceptions.hpp"
class DateTime : public Date, public Time
{
public:
    DateTime(void) : Date(), Time(){};
    DateTime(int y);
    DateTime(int y, int m);
    DateTime(int y, int m, int d);
    DateTime(int y, int m, int d, int h);
    DateTime(int y, int m, int d, int h, int minute);
    friend std::istream &operator>>(std::istream &in, DateTime &dt);
    friend std::ostream &operator<<(std::ostream &out, DateTime &dt);
    bool operator<(const DateTime &dt);
    bool operator>(const DateTime &dt);
    bool operator==(const DateTime &dt);
    bool operator<=(const DateTime &dt);
    bool operator>=(const DateTime &dt);
    DateTime operator+(const DateTime &dt);
    operator std::string();
    void setYear(int y);
    void setMonth(int m);
    void setDay(int d);
    void setHour(int h);
    void setMinute(int m);
};
#endif