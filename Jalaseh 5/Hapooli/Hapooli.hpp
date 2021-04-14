/*
--------------------------------------------------
Name    : Hapooli
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 07/Apr/2021
--------------------------------------------------
*/
#include <string>
class Student
{
private:
    std::string _firstName;
    std::string _lastName;
    const std::string _studentNumber;
    int _grade;
    static int studentCount;
    static int gradesSum;
    static int id;
    std::string createStudentNumber(void);

public:
    Student(std::string firstName,
            std::string lastName);
    Student(std::string firstName,
            std::string lastName,
            int grade);
    ~Student(void);
    void setFirstName(std::string firstName);
    std::string getFirstName(void);
    void setLastName(std::string lastName);
    std::string getLastName(void);
    std::string getStudentNumber(void);
    void setGrade(int grade);
    int getGrade(void);
    static double getAverage(void);
    static int getStudentsCount(void);
};
