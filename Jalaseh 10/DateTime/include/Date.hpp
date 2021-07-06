/*
--------------------------------------------------
Name    : DateTime
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 21/May/2021
--------------------------------------------------
*/
#ifndef DATE_HPP_
#define DATE_HPP_
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Exceptions.hpp"
#include "Utility.hpp"
class Date {
 public:
  Date(void);
  Date(int y);
  Date(int y, int m);
  Date(int y, int m, int d);
  friend std::istream &operator>>(std::istream &in, Date &d);
  friend std::ostream &operator<<(std::ostream &out, Date &d);
  bool operator<(const Date &d);
  bool operator>(const Date &d);
  bool operator==(const Date &d);
  bool operator<=(const Date &d);
  bool operator>=(const Date &d);
  Date operator+(const Date &d);
  operator std::string(void);
  inline int getYear(void) { return year; }
  inline int getMonth(void) { return month; }
  inline int getDay(void) { return day; }
  inline void setDate(int y, int m, int d) {
    setYear(y);
    setMonth(m);
    setDay(d);
  }
  void setYear(int y);
  void setMonth(int m);
  void setDay(int d);

 protected:
  int year;
  int month;
  int day;
};
#endif