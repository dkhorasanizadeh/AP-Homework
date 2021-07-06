/*
--------------------------------------------------
Name    : CDShop
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 16/May/2021
--------------------------------------------------
*/
#include <iostream>

#include "include/CD.hpp"
int main(void) {
  int numberOfCDs, type;
  std::cin >> numberOfCDs;
  CDShop::CD **CDObjects = new CDShop::CD *[numberOfCDs];
  for (int i = 0; i < numberOfCDs; i++) {
    std::cin >> type;
    CDObjects[i] = CDShop::CD::CreateCD(type);
    CDObjects[i]->setData();
  }
  for (int i = 0; i < numberOfCDs; i++) {
    CDObjects[i]->showData();
  }
  int numberOfQueries, query, id;
  std::cin >> numberOfQueries;
  for (int i = 0; i < numberOfQueries; i++) {
    std::cin >> id >> query;
    CDShop::Movie *movie = dynamic_cast<CDShop::Movie *>(CDObjects[id - 1]);
    if (!(query == 0 || query == 1) || movie == nullptr) {
      std::cout << "ERROR" << std::endl;
      continue;
    }
    if (query == 0) {
      std::cout << movie->returnMovie() << std::endl;
    } else if (query == 1) {
      std::cout << movie->rentMovie() << std::endl;
    }
  }
  return 0;
}