/*
--------------------------------------------------
Name    : Hapooli
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 07/Apr/2021
--------------------------------------------------
*/
#include <iostream>

#include "Hapooli.hpp"

int main(void) {
  Student a("Ali", "Rezaie", 11);
  Student b("Mohamaad", "Aboo");
  std::cout << a.getStudentNumber() << std::endl;
  b.setGrade(20);
  std::cout << Student::getAverage() << std::endl;
  b.setGrade(10);
  std::cout << Student::getAverage() << std::endl;
  std::cout << Student::getStudentsCount() << std::endl;
  std::cout << b.getStudentNumber() << std::endl;
  b.~Student();
  Student c("Asghar", "Mohammadi");
  std::cout << c.getStudentNumber() << std::endl;
  std::cout << Student::getStudentsCount() << std::endl;
  std::cout << Student::getAverage() << std::endl;
  return 0;
}