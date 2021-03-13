/*
--------------------------------------------------
Name    : Time
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 10/Mar/2021
--------------------------------------------------
*/
#include <iostream>
using namespace std;
class Time
{
public:
    Time(int h);
    Time(int h, int m);
    void setHour(int h);
    void setMinute(int m);
    int getHour(void) { return hour; };
    int getMinute(void) { return minute; };
    int compare(Time t);
    string timeToString(void);

private:
    int hour;
    int minute;
};
Time::Time(int h)
{
    if (h >= 0 && h <= 23)
    {
        hour = h;
    }
    else
    {
        cout << "Invalid Value" << endl;
        abort();
    }
    minute = 0;
    cout << "Object Created" << endl;
}
Time::Time(int h, int m)
{
    if (h >= 0 && h <= 23)
    {
        hour = h;
    }
    else
    {
        cout << "Invalid Value" << endl;
        abort();
    }
    if (m >= 0 && m <= 59)
    {
        minute = m;
    }
    else
    {
        cout << "Invalid Value" << endl;
        abort();
    }
    cout << "Object Created" << endl;
}
void Time::setHour(int h)
{
    if (h >= 0 && h <= 23)
    {
        hour = h;
    }
    else
    {
        cout << "Invalid Value" << endl
             << "Nothing Changed" << endl;
    }
}
void Time::setMinute(int m)
{
    if (m >= 0 && m <= 60)
    {
        minute = m;
    }
    else
    {
        cout << "Invalid Value" << endl
             << "Nothing Changed" << endl;
    }
}
int Time::compare(Time t)
{
    if (hour > t.hour)
    {
        return 1;
    }
    else if (hour < t.hour)
    {
        return -1;
    }
    else
    {
        if (minute > t.minute)
        {
            return 1;
        }
        else if (minute < t.minute)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}
string Time::timeToString(void)
{
    if (hour >= 0 && hour < 12)
    {
        return "Morning";
    }
    else if (hour == 12 && minute == 0)
    {
        return "Noon";
    }
    else if (hour >= 12 && hour < 17)
    {
        return "After Noon";
    }
    else if (hour >= 17 && hour < 20)
    {
        return "Evening";
    }
    else if (hour >= 20 && hour <= 23)
    {
        return "Night";
    }
    return "None";
}
int main(void)
{
    return 0;
}