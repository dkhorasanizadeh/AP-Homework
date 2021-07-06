/*
--------------------------------------------------
Name    :
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 27/Apr/2021
--------------------------------------------------
*/
#include <iostream>

#include "List.hpp"
int main(void) {
  List<int> i;
  i.insert(1);
  i.insert(2);
  TwoDList<int> a;
  a.insert(i);
  a.insert(3);
  a(0, 0) = 25;
  std::cout << i[1] << std::endl;
  std::cout << a;
  return 0;
}