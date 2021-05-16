/*
--------------------------------------------------
Name    : DateTime
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 05/May/2021
--------------------------------------------------
*/
#include "../include/DateTime.hpp"
std::istream &operator>>(std::istream &in, DateTime &dt)
{
    Date d;
    Time t;
    in >> d >> t;
    dt.year = d.getYear();
    dt.month = d.getMonth();
    dt.day = d.getDay();
    dt.hour = t.getHour();
    dt.minute = t.getMinute();
    return in;
}
std::ostream &operator<<(std::ostream &out, DateTime &dt)
{
    Date *d = &dt;
    Time *t = &dt;
    out << *d << " " << *t;
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
    if (Date::operator>(dt))
    {
        return true;
    }
    else if (Date::operator<(dt))
    {
        return false;
    }
    else
    {
        return Time::operator>(dt);
    }
}
bool DateTime::operator==(const DateTime &dt)
{
    return Date::operator==(dt) && Time::operator==(dt);
}
bool DateTime::operator<=(const DateTime &dt)
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
        return Time::operator<=(dt);
    }
}
bool DateTime::operator>=(const DateTime &dt)
{
    if (Date::operator>(dt))
    {
        return true;
    }
    else if (Date::operator<(dt))
    {
        return false;
    }
    else
    {
        return Time::operator>=(dt);
    }
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