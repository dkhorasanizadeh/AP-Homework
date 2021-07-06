#include <cassert>
#include <iostream>
using namespace std;

int main(void) {
  int arr[] = {10, 20, 30, 40, 50, 60};
  int *ptr1 = arr;
  int *ptr2 = arr + 5;
  assert(*ptr1 == 10);
  assert(*ptr2 == 60);
  cout << (*ptr2 - *ptr1) << endl;
  cout << (char)(*ptr2 - *ptr1) << endl;
  return 0;
}