/*
--------------------------------------------------
Name    : Emtiazi
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 22/Feb/2021
--------------------------------------------------
*/
#include <iostream>
#include <vector>
using namespace std;
int maxEmtiaz = 0;
int findMax(int a, int b) { return a >= b ? a : b; }
int max(vector<int> nums, int size, int i) {
  int maxNow = 0;
  if (i == 0) {
    maxEmtiaz = findMax(maxEmtiaz, nums[i]);
    return nums[i];
  }
  maxNow = findMax(nums[i], nums[i] + max(nums, size, i - 1));
  maxEmtiaz = findMax(maxEmtiaz, maxNow);
  return maxNow;
}
int main(void) {
  int n, temp;
  cin >> n;
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    nums.push_back(temp);
  }
  max(nums, n, n - 1);
  cout << maxEmtiaz;
  return 0;
}