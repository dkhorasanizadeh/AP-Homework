#include <iostream>
#include <cassert>
using namespace std;

int main(void)
{
    float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
    float *ptr1 = &arr[0];
    float *ptr2 = ptr1 + 3;
    assert(*ptr2 == 90.5);
    assert(*ptr1 == 12.5);
    cout << *ptr2 - *ptr1;
    return 0;
}
