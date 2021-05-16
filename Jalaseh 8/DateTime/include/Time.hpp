/*
--------------------------------------------------
Name    : DateTime
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 05/May/2021
--------------------------------------------------
*/
#ifndef TIME_HPP_
#define TIME_HPP_
#include <vector>
#include <string>
#include <iostream>
#include "Utility.hpp"
class Time
{
public:
    Time(void);
    Time(int h);
    Time(int h, int m);
    friend std::istream &operator>>(std::istream &in, Time &t);
    friend std::ostream &operator<<(std::ostream &out, Time &t);
    bool operator<(const Time &t);
    bool operator>(const Time &t);
    bool operator==(const Time &t);
    bool operator<=(const Time &t);
    bool operator>=(const Time &t);
    Time operator+(const Time &t);
    operator std::string(void);
    inline int getHour(void) { return hour; }
    inline int getMinute(void) { return minute; }

protected:
    int hour;
    int minute;
};
#endif