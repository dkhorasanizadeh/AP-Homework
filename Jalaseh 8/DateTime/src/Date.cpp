/*
--------------------------------------------------
Name    : DateTime
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 05/May/2021
--------------------------------------------------
*/
#include "../include/Date.hpp"
Date::Date(void)
{
    year = 1300;
    month = 1;
    day = 1;
}
Date::Date(int y)
{
    assert(y > 0);
    year = y;
    month = 1;
    day = 1;
}
Date::Date(int y, int m)
{
    assert(y > 0);
    assert(m > 0);
    assert(m < 13);
    year = y;
    month = m;
    day = 1;
}
Date::Date(int y, int m, int d)
{
    assert(y > 0);
    assert(m > 0);
    assert(m < 13);
    assert(d > 0);
    year = y;
    month = m;
    if (month >= 1 && month <= 6)
    {
        assert(d < 32);
        day = d;
    }
    else if (month >= 7 && month <= 11)
    {
        assert(d < 31);
        day = d;
    }
    else if (month == 12)
    {
        assert(d < 30);
        day = d;
    }
}
std::istream &operator>>(std::istream &in, Date &d)
{
    std::string Date;
    in >> Date;
    std::vector<std::string> splitDate = split(Date, "/");
    if (splitDate.size() == 1)
    {
        int y = std::stoi(splitDate[0]);
        assert(y > 0);
        d.year = y;
        d.month = 1;
        d.day = 1;
    }
    else if (splitDate.size() == 2)
    {
        int y = std::stoi(splitDate[0]);
        int m = std::stoi(splitDate[1]);
        assert(y > 0);
        assert(m > 0);
        assert(m < 13);
        d.year = y;
        d.month = m;
        d.day = 1;
    }
    else if (splitDate.size() == 3)
    {
        int y = std::stoi(splitDate[0]);
        int m = std::stoi(splitDate[1]);
        int _day = std::stoi(splitDate[2]);
        assert(y > 0);
        assert(m > 0);
        assert(m < 13);
        assert(_day > 0);
        d.year = y;
        d.month = m;
        if (d.month >= 1 && d.month <= 6)
        {
            assert(_day < 32);
            d.day = _day;
        }
        else if (d.month >= 7 && d.month <= 11)
        {
            assert(_day < 31);
            d.day = _day;
        }
        else if (d.month == 12)
        {
            assert(_day < 30);
            d.day = _day;
        }
    }
    else
    {
        d.year = 1300;
        d.month = 1;
        d.day = 1;
    }
    return in;
}
std::ostream &operator<<(std::ostream &out, Date &d)
{
    out << makeTwoDigit(d.year) << "/" << makeTwoDigit(d.month) << "/" << makeTwoDigit(d.day);
    return out;
}
bool Date::operator>(const Date &d)
{
    if (year > d.year)
    {
        return true;
    }
    else if (year < d.year)
    {
        return false;
    }
    else
    {
        if (month > d.month)
        {
            return true;
        }
        else if (month < d.month)
        {
            return false;
        }
        else
        {
            if (day > d.day)
            {
                return true;
            }
            else if (day < d.day)
            {
                return false;
            }
            else
            {
                return false;
            }
        }
    }
}
bool Date::operator<(const Date &d)
{
    if (year < d.year)
    {
        return true;
    }
    else if (year > d.year)
    {
        return false;
    }
    else
    {
        if (month < d.month)
        {
            return true;
        }
        else if (month > d.month)
        {
            return false;
        }
        else
        {
            if (day < d.day)
            {
                return true;
            }
            else if (day > d.day)
            {
                return false;
            }
            else
            {
                return false;
            }
        }
    }
}
bool Date::operator<=(const Date &d)
{
    if (year < d.year)
    {
        return true;
    }
    else if (year > d.year)
    {
        return false;
    }
    else
    {
        if (month < d.month)
        {
            return true;
        }
        else if (month > d.month)
        {
            return false;
        }
        else
        {
            if (day < d.day)
            {
                return true;
            }
            else if (day > d.day)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
}
bool Date::operator>=(const Date &d)
{
    if (year > d.year)
    {
        return true;
    }
    else if (year < d.year)
    {
        return false;
    }
    else
    {
        if (month > d.month)
        {
            return true;
        }
        else if (month < d.month)
        {
            return false;
        }
        else
        {
            if (day > d.day)
            {
                return true;
            }
            else if (day < d.day)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
}
bool Date::operator==(const Date &d)
{
    if (day == d.day && month == d.month && year == d.year)
    {
        return true;
    }
    return false;
}
Date Date::operator+(const Date &d)
{
    int y, m, _day;
    y = year + d.year;
    m = month + d.month;
    _day = day + d.day;
    m = ((m - 1) % 12) + 1;
    if (m >= 1 && m <= 6)
    {
        _day = ((_day - 1) % 31) + 1;
    }
    else if (m >= 7 && m <= 11)
    {
        _day = ((_day - 1) % 30) + 1;
    }
    else if (m == 12)
    {
        _day = ((_day - 1) % 29) + 1;
    }
    Date Date(y, m, _day);
    return Date;
}
Date::operator std::string()
{
    std::stringstream s;
    s << year << "/" << month << "/" << day;
    return s.str();
}