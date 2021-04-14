/*
--------------------------------------------------
Name    : Hapooli
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 07/Apr/2021
--------------------------------------------------
*/
#include "Hapooli.hpp"
#include <string>
#include <sstream>

int Student::studentCount = 0;
int Student::gradesSum = 0;
int Student::id = 0;
Student::Student(std::string firstName, std::string lastName) : _studentNumber(createStudentNumber())
{
    studentCount++;
    _firstName = firstName;
    _lastName = lastName;
    _grade = 0;
    gradesSum += _grade;
}
Student::Student(std::string firstName, std::string lastName, int grade) : _studentNumber(createStudentNumber())
{
    studentCount++;
    _firstName = firstName;
    _lastName = lastName;
    _grade = grade;
    gradesSum += _grade;
}
Student::~Student(void)
{
    gradesSum -= _grade;
    studentCount--;
}
std::string Student::createStudentNumber(void)
{
    std::stringstream stringStream;
    id++;
    stringStream << "99" << id << "3";
    return stringStream.str();
}
void Student::setFirstName(std::string firstName)
{
    _firstName = firstName;
}
std::string Student::getFirstName(void)
{
    return _firstName;
}
void Student::setLastName(std::string lastName)
{
    _lastName = lastName;
}
std::string Student::getLastName(void)
{
    return _lastName;
}
std::string Student::getStudentNumber(void)
{
    return _studentNumber;
}
void Student::setGrade(int grade)
{
    gradesSum -= _grade;
    _grade = grade;
    gradesSum += grade;
}
int Student::getGrade(void)
{
    return _grade;
}
double Student::getAverage(void)
{
    return (double)Student::gradesSum / (double)Student::studentCount;
}
int Student::getStudentsCount(void)
{
    return Student::studentCount;
}
