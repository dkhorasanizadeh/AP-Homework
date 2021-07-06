/*
--------------------------------------------------
Name    : DateTime
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 21/May/2021
--------------------------------------------------
*/
#include "../include/Date.hpp"
Date::Date(void) { setDate(1300, 1, 1); }
Date::Date(int y) { setDate(y, 1, 1); }
Date::Date(int y, int m) { setDate(y, m, 1); }
Date::Date(int y, int m, int d) { setDate(y, m, d); }
std::istream &operator>>(std::istream &in, Date &d) {
  std::string Date;
  in >> Date;
  std::vector<int> splitDate = split(Date, "/");
  if (splitDate.size() == 1) {
    d.setDate(splitDate[0], 1, 1);
  } else if (splitDate.size() == 2) {
    d.setDate(splitDate[0], splitDate[1], 1);
  } else if (splitDate.size() == 3) {
    d.setDate(splitDate[0], splitDate[1], splitDate[2]);
  } else {
    d.setDate(1300, 1, 1);
  }
  return in;
}
std::ostream &operator<<(std::ostream &out, Date &d) {
  out << std::string(d);
  return out;
}
bool Date::operator>(const Date &d) {
  if (year > d.year) {
    return true;
  } else if (year == d.year) {
    if (month > d.month) {
      return true;
    } else if (month == d.month) {
      if (day > d.day) {
        return true;
      }
    }
  }
  return false;
}
bool Date::operator<(const Date &d) { return !operator>=(d); }
bool Date::operator<=(const Date &d) { return operator==(d) || operator<(d); }
bool Date::operator>=(const Date &d) { return operator==(d) || operator>(d); }
bool Date::operator==(const Date &d) {
  if (day == d.day && month == d.month && year == d.year) {
    return true;
  }
  return false;
}
Date Date::operator+(const Date &d) {
  int y, m, _day;
  y = year + d.year;
  m = month + d.month;
  _day = day + d.day;
  m = ((m - 1) % 12) + 1;
  if (m >= 1 && m <= 6) {
    _day = ((_day - 1) % 31) + 1;
  } else if (m >= 7 && m <= 11) {
    _day = ((_day - 1) % 30) + 1;
  } else if (m == 12) {
    _day = ((_day - 1) % 29) + 1;
  }
  Date Date(y, m, _day);
  return Date;
}
Date::operator std::string() {
  std::stringstream s;
  s << makeTwoDigit(year) << "/" << makeTwoDigit(month) << "/"
    << makeTwoDigit(day);
  return s.str();
}
void Date::setYear(int y) {
  if (y < 0) {
    throw DateException("Bad Year", y);
  }
  year = y;
}
void Date::setMonth(int m) {
  if (m > 12 || m < 1) {
    throw std::out_of_range("Bad Month Value");
  }
  month = m;
}
void Date::setDay(int d) {
  if (d < 1 || d > 30) {
    throw d;
  }
  day = d;
}