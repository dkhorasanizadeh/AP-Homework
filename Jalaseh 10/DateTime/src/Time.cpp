/*
--------------------------------------------------
Name    : DateTime
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 21/May/2021
--------------------------------------------------
*/
#include "../include/Time.hpp"
Time::Time(void) { setTime(0, 0); }
Time::Time(int h) { setTime(h, 0); }
Time::Time(int h, int m) { setTime(h, m); }
std::istream &operator>>(std::istream &in, Time &t) {
  std::string time;
  in >> time;
  std::vector<int> splitTime = split(time, ":");
  if (splitTime.size() == 1) {
    t.setTime(splitTime[0], 0);
  } else if (splitTime.size() > 1) {
    t.setTime(splitTime[0], splitTime[1]);
  } else {
    t.setTime(0, 0);
  }
  return in;
}
std::ostream &operator<<(std::ostream &out, Time &t) {
  out << std::string(t);
  return out;
}
bool Time::operator>(const Time &t) {
  if (hour > t.hour) {
    return true;
  } else if (hour == t.hour) {
    if (minute > t.minute) {
      return true;
    }
  }
  return false;
}
bool Time::operator<(const Time &t) { return !operator>=(t); }
bool Time::operator<=(const Time &t) { return operator==(t) || operator<(t); }
bool Time::operator>=(const Time &t) { return operator==(t) || operator>(t); }
bool Time::operator==(const Time &t) {
  if (hour == t.hour && minute == t.minute) {
    return true;
  }
  return false;
}
Time Time::operator+(const Time &t) {
  int h, m;
  h = hour + t.hour;
  m = minute + t.minute;
  h += minute / 60;
  h = h % 24;
  m = m % 60;
  Time time(h, m);
  return time;
}
Time::operator std::string(void) {
  if (hour >= 0 && hour < 12) {
    return "Morning";
  } else if (hour == 12 && minute == 0) {
    return "Noon";
  } else if (hour >= 12 && hour < 17) {
    return "After Noon";
  } else if (hour >= 17 && hour < 20) {
    return "Evening";
  } else if (hour >= 20 && hour <= 23) {
    return "Night";
  }
  return "None";
}
void Time::setHour(int h) {
  if (h >= 24 || h < 0) {
    throw TimeException("Bad Hour", h);
  }
  hour = h;
}
void Time::setMinute(int m) {
  if (m >= 60 || m < 0) {
    throw TimeException("Bad Minute", m);
  }
  minute = m;
}