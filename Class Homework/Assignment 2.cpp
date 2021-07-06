#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

class Date {
 public:
  Date();
  Date(int y, int m, int d);
  void setDate(int y, int m, int d);
  void printDate();
  bool equals(Date d);
  int getYear();
  int getMonth();
  int getDay() { return day; };
  int compare(Date d);

 private:
  int day;
  int month;
  int year;
};

int daysOfMonth(int m);
Date str2Date(string s);
int main() {}
int daysOfMonth(int m) {
  if (m >= 1 && m <= 7) {
    return 31;
  } else if (m >= 8 && m <= 11) {
    return 30;
  } else if (m == 12) {
    return 29;
  }
  return 0;
}
Date::Date() {
  cout << "Constructor with no arguments." << endl;
  setDate(1399, 12, 13);
}
Date::Date(int y, int m, int d) {
  cout << "Constructor with arguments." << endl;
  setDate(y, m, d);
}
void Date::setDate(int y, int m, int d) {
  if (y < 0 || m < 1 || m > 12 || d > daysOfMonth(m)) {
    cout << "Invalid Date." << endl;
    setDate(1399, 12, 13);
    return;
  }
  year = y;
  month = m;
  day = d;
}
void Date::printDate() { cout << year << "/" << month << "/" << day << endl; }
bool Date::equals(Date d) {
  return day == d.day && month == d.month && year == d.year;
}
inline int Date::getYear() { return year; }
inline int Date::getMonth() { return month; }
int Date::compare(Date d) {
  if (year < d.year) {
    return -1;
  } else if (year > d.year) {
    return 1;
  } else {
    if (month < d.month) {
      return -1;
    } else if (month > d.month) {
      return 1;
    } else {
      if (day < d.day) {
        return -1;
      } else if (day > d.day) {
        return 1;
      } else {
        return 0;
      }
    }
  }
}
Date str2Date(string s) {
  char *s_CString = (char *)s.c_str();
  char *token = strtok(s_CString, "/");
  int y, m, d;
  y = stoi(token);
  token = strtok(NULL, "/");
  m = stoi(token);
  token = strtok(NULL, "/");
  d = stoi(token);
  Date fromStrDate(y, m, d);
  return fromStrDate;
}