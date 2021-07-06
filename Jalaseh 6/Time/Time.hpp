/*
--------------------------------------------------
Name    : Time
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 14/Apr/2021
--------------------------------------------------
*/
#ifndef TIME_HPP_
#define TIME_HPP_
#include <string>
class Time {
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
  operator std::string();

 private:
  int hour;
  int minute;
};
#endif