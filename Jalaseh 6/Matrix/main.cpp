/*
--------------------------------------------------
Name    : Matrix
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 17/Apr/2021
--------------------------------------------------
*/
#include <iostream>

#include "Matrix.hpp"
int main(void) {
  Matrix<int> a, b;
  std::cin >> a >> b;
  a += b;
  std::cout << a;
  Matrix<char *> c, d;
  std::cin >> c;
  std::cin >> d;
  Matrix<char *> e = c + d;
  std::cout << e;
  return 0;
}