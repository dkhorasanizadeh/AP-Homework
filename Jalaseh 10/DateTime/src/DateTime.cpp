/*
--------------------------------------------------
Name    : DateTime
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 21/May/2021
--------------------------------------------------
*/
#include "../include/DateTime.hpp"
std::istream &operator>>(std::istream &in, DateTime &dt)
{
    std::string input;
    std::smatch values;
    std::regex DateTimeMatch("(\\d+)\\/?(\\d*)\\/?(\\d*)\\s*(\\d*):?(\\d*)");
    std::getline(in, input);
    std::regex_search(input, values, DateTimeMatch);
    if (values[1].length())
    {
        dt.setYear(std::stoi(values[1].str()));
    }
    else
    {
        throw DateTimeException("Year Not Specified", -1);
    }
    if (values[2].length())
    {
        dt.setMonth(std::stoi(values[2].str()));
    }
    else
    {
        dt.setMonth(1);
    }
    if (values[3].length())
    {
        dt.setDay(std::stoi(values[3].str()));
    }
    else
    {
        dt.setDay(1);
    }
    if (values[4].length())
    {
        dt.setHour(std::stoi(values[4].str()));
    }
    else
    {
        dt.setHour(0);
    }
    if (values[5].length())
    {
        dt.setMinute(std::stoi(values[5].str()));
    }
    else
    {
        dt.setMinute(0);
    }
    return in;
}
std::ostream &operator<<(std::ostream &out, DateTime &dt)
{
    out << std::string(dt);
    return out;
}
bool DateTime::operator<(const DateTime &dt)
{
    if (Date::operator<(dt))
    {
        return true;
    }
    else if (Date::operator>(dt))
    {
        return false;
    }
    else
    {
        return Time::operator<(dt);
    }
}
bool DateTime::operator>(const DateTime &dt)
{
    return !operator<=(dt);
}
bool DateTime::operator==(const DateTime &dt)
{
    return Date::operator==(dt) && Time::operator==(dt);
}
bool DateTime::operator<=(const DateTime &dt)
{
    return operator<(dt) || operator==(dt);
}
bool DateTime::operator>=(const DateTime &dt)
{
    return operator>(dt) || operator==(dt);
}
DateTime DateTime::operator+(const DateTime &dt)
{
    Time t = Time::operator+(dt);
    Date d = Date::operator+(dt);
    DateTime newDt(d.getYear(), d.getMonth(), d.getDay(), t.getHour(), t.getMinute());
    return newDt;
}
DateTime::operator std::string()
{
    Date *d = this;
    Time *t = this;
    return std::string(*d) + " " + std::string(*t);
}
DateTime::DateTime(int y)
{
    setYear(y);
}
DateTime::DateTime(int y, int m)
{
    setYear(y);
    setMonth(m);
}
DateTime::DateTime(int y, int m, int d)
{
    setYear(y);
    setMonth(m);
    setDay(d);
}
DateTime::DateTime(int y, int m, int d, int h)
{
    setYear(y);
    setMonth(m);
    setDay(d);
    setHour(h);
}
DateTime::DateTime(int y, int m, int d, int h, int minute)
{
    setYear(y);
    setMonth(m);
    setDay(d);
    setHour(h);
    setMinute(minute);
}
void DateTime::setYear(int y)
{
    try
    {
        Date::setYear(y);
    }
    catch (DateException &de)
    {
        throw DateTimeException("Bad Year", de.getValue());
    }
}
void DateTime::setMonth(int m)
{
    try
    {
        Date::setMonth(m);
    }
    catch (std::out_of_range &de)
    {
        Date::setMonth(1);
    }
}
void DateTime::setDay(int d)
{
    try
    {
        Date::setDay(d);
    }
    catch (int &day)
    {
        if (day < 1)
        {
            Date::setDay(1);
        }
        else if (d > 30)
        {
            Date::setDay(30);
        }
    }
}
void DateTime::setHour(int h)
{
    try
    {
        Time::setHour(h);
    }
    catch (TimeException &te)
    {
        throw DateTimeException("Bad Hour", te.getValue());
    }
}
void DateTime::setMinute(int m)
{
    try
    {
        Time::setMinute(m);
    }
    catch (TimeException &te)
    {
        if (te.getValue() > 60)
        {
            Time::setMinute(59);
        }
        else if (te.getValue() < 0)
        {
            Time::setMinute(0);
        }
    }
}