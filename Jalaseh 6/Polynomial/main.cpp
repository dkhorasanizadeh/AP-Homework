/*
--------------------------------------------------
Name    : Polynomial
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 19/Apr/2021
--------------------------------------------------
*/
#include <iostream>
#include "Polynomial.hpp"
int main(void)
{
    Polynomial i;
    Polynomial j;
    std::cin >> i;
    std::cin >> j;
    Polynomial k = i * j;
    k = -k;
    std::cout << k;
    return 0;
}