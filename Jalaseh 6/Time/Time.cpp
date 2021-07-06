/*
--------------------------------------------------
Name    : Time
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 14/Apr/2021
--------------------------------------------------
*/
#include "Time.hpp"

#include <iostream>
#include <string>
#include <vector>
std::vector<std::string> split(std::string s, std::string delimiter) {
  int pos_start = 0, pos_end, delim_len = delimiter.length();
  std::string token;
  std::vector<std::string> res;
  while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
    token = s.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    res.push_back(token);
  }
  res.push_back(s.substr(pos_start));
  return res;
}
Time::Time(void) {
  hour = 0;
  minute = 0;
}
Time::Time(int h) {
  hour = h % 24;
  minute = 0;
}
Time::Time(int h, int m) {
  h = h + (m / 60);
  hour = h % 24;
  minute = m % 60;
}
std::istream &operator>>(std::istream &in, Time &t) {
  std::string time;
  in >> time;
  std::vector<std::string> splitTime = split(time, ":");
  if (splitTime.size() == 1) {
    t.hour = std::stoi(splitTime[0]) % 24;
    t.minute = 0;
  } else if (splitTime.size() > 1) {
    int h = std::stoi(splitTime[0]) + (std::stoi(splitTime[1]) / 60);
    t.hour = h % 24;
    t.minute = std::stoi(splitTime[1]) % 60;
  } else {
    t.hour = 0;
    t.minute = 0;
  }
  return in;
}
std::ostream &operator<<(std::ostream &out, Time &t) {
  out << t.hour << ":" << t.minute;
  return out;
}
bool Time::operator>(const Time &t) {
  if (hour > t.hour) {
    return true;
  } else if (hour < t.hour) {
    return false;
  } else {
    if (minute > t.minute) {
      return true;
    } else if (minute < t.minute) {
      return false;
    } else {
      return false;
    }
  }
}
bool Time::operator<(const Time &t) {
  if (hour < t.hour) {
    return true;
  } else if (hour > t.hour) {
    return false;
  } else {
    if (minute < t.minute) {
      return true;
    } else if (minute > t.minute) {
      return false;
    } else {
      return false;
    }
  }
}
bool Time::operator<=(const Time &t) {
  if (hour < t.hour) {
    return true;
  } else if (hour > t.hour) {
    return false;
  } else {
    if (minute < t.minute) {
      return true;
    } else if (minute > t.minute) {
      return false;
    } else {
      return true;
    }
  }
}
bool Time::operator>=(const Time &t) {
  if (hour > t.hour) {
    return true;
  } else if (hour < t.hour) {
    return false;
  } else {
    if (minute > t.minute) {
      return true;
    } else if (minute < t.minute) {
      return false;
    } else {
      return true;
    }
  }
}
bool Time::operator==(const Time &t) {
  if (hour > t.hour) {
    return false;
  } else if (hour < t.hour) {
    return false;
  } else {
    if (minute > t.minute) {
      return false;
    } else if (minute < t.minute) {
      return false;
    } else {
      return true;
    }
  }
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
Time::operator std::string() {
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