/*
--------------------------------------------------
Name    : DateTime
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 05/May/2021
--------------------------------------------------
*/
#include <iostream>

#include "./include/DateTime.hpp"
int main(void) {
  DateTime a(1302, 2, 3, 12, 24);
  DateTime b(1301, 10, 23);
  DateTime c;
  std::cin >> c;
  DateTime d = b + c;
  if (a < b) {
    std::cout << std::string(c);
  } else {
    std::cout << d;
  }
  return 0;
}