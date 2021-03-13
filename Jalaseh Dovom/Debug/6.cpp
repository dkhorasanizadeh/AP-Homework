#include <iostream>
#include <cassert>
using namespace std;

int main(void)
{
	int a;
	char *x;
	x = (char *)&a;
	a = 512;
	x[0] = 1;
	assert(a == 513);
	cout << a;
	return 0;
}
