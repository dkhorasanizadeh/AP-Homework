/*
--------------------------------------------------
Name    : DateTime
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 21/May/2021
--------------------------------------------------
*/
#include <iostream>
#include "./include/DateTime.hpp"
int main(void)
{
    DateTime a(1300, 2, 3, 12, 24);
    DateTime b(1301, 10, 23);
    DateTime c;
    std::cin >> c;
    DateTime d = b + c;
    if (a < b)
    {
        std::cout << std::string(c) << std::endl;
    }
    else
    {
        std::cout << d << std::endl;
    }
    try
    {
        DateTime e(1200, 2, 3, 25, 24);
        std::cout << e << std::endl;
    }
    catch (DateTimeException &dte)
    {
        std::cout << dte.getMessage() << ":" << dte.getValue() << std::endl;
    }
    try
    {
        DateTime f(-1301, 10, 23, 15, 44);
        std::cout << f << std::endl;
    }
    catch (DateTimeException &dte)
    {
        std::cout << dte.getMessage() << ":" << dte.getValue() << std::endl;
    }
    try
    {
        DateTime g(1400, 23, 19, 12, 69);
        std::cout << g << std::endl;
    }
    catch (DateTimeException &dte)
    {
        std::cout << dte.getMessage() << ":" << dte.getValue() << std::endl;
    }
    return 0;
}