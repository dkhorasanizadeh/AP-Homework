/*
--------------------------------------------------
Name    : Chideman
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 22/Feb/2021
--------------------------------------------------
*/
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    long long int temp, n, average = 0, minutes = 0;
    cin >> n;
    vector<long long int> nums;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        average += temp;
        nums.push_back(temp);
    }
    average /= n;
    for (int i = 0; i < n; i++)
    {
        nums[i] -= average;
        if (nums[i] > 0)
        {
            minutes += nums[i];
        }
    }
    cout << minutes;
    return 0;
}