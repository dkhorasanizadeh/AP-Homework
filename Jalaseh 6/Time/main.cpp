/*
--------------------------------------------------
Name    : Time
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 14/Apr/2021
--------------------------------------------------
*/
#include <iostream>
#include "Time.hpp"
int main(void)
{
    Time a(15, 12);
    Time b(12, 11);
    std::cout << (a >= b) << std::endl;
    Time c = a + b;
    std::cout << c;
    return 0;
}