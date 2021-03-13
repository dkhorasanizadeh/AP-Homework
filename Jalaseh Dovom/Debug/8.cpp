#include <iostream>
#include <cassert>
using namespace std;

const char *f(const char **p);

int main(void)
{
	const char *str[] = {"Wish", "You", "Best", ":D"};
	cout << *f(str) << *(f(str) + 1) << " ";
	cout << **str << *(*(str + 1) + 1) << *((str + 2)[-1] + 1) << **&*(&str[-1] + 1);
	return 0;
}

const char *f(const char **p)
{
	auto q = (p + sizeof(char))[1];
	return q;
}