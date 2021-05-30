/*
--------------------------------------------------
Name    : DateTime
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 21/May/2021
--------------------------------------------------
*/
#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP
#include <iostream>
#include <exception>
class Exception : public std::exception
{
private:
    std::string Message;
    int Value;

public:
    Exception(std::string message, int value)
    {
        Message = message;
        Value = value;
    }
    const char *what() const throw()
    {
        return Message.c_str();
    }
    int getValue(void)
    {
        return Value;
    }
    std::string getMessage(void)
    {
        return Message;
    }
};
class TimeException : public Exception
{
public:
    TimeException(std::string message, int value) : Exception(message, value) {}
};
class DateException : public Exception
{
public:
    DateException(std::string message, int value) : Exception(message, value) {}
};
class DateTimeException : public Exception
{
public:
    DateTimeException(std::string message, int value) : Exception(message, value) {}
};
#endif