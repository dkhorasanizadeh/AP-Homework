#include <iostream>
#include <cassert>
using namespace std;

int main(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	int *p = arr;
	++*p;
	p += 2;
	assert(*p == 3);
	cout << *p;
	return 0;
}