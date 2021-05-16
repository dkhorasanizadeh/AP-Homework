/*
--------------------------------------------------
Name    : Chand Mazrabi
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 05/May/2021
--------------------------------------------------
*/
#include <iostream>
class A
{
public:
    A(void)
    {
        callA = 0;
    }

private:
    int callA;
    void inc(void)
    {
        callA++;
    }

protected:
    void func(int &a)
    {
        a = a * 2;
        inc();
    }

public:
    int getA(void)
    {
        return callA;
    }
};

class B
{
public:
    B(void)
    {
        callB = 0;
    }

private:
    int callB;
    void inc(void)
    {
        callB++;
    }

protected:
    void func(int &a)
    {
        a = a * 3;
        inc();
    }

public:
    int getB(void)
    {
        return callB;
    }
};

class C
{
public:
    C(void)
    {
        callC = 0;
    }

private:
    int callC;
    void inc(void)
    {
        callC++;
    }

protected:
    void func(int &a)
    {
        a = a * 5;
        inc();
    }

public:
    int getC(void)
    {
        return callC;
    }
};

class D : public A, public B, public C
{
private:
    int val;

public:
    D(void)
    {
        val = 1;
    }
    void update_val(int new_val)
    {
        while (!(new_val % 5))
        {
            C::func(val);
            new_val /= 5;
        }
        while (!(new_val % 3))
        {
            B::func(val);
            new_val /= 3;
        }
        while (!(new_val % 2))
        {
            A::func(val);
            new_val /= 2;
        }
    }
    void check(int);
};

void D::check(int new_val)
{
    update_val(new_val);
    std::cout << "Value = " << val << std::endl
              << "A's func called " << getA() << " times" << std::endl
              << "B's func called " << getB() << " times" << std::endl
              << "C's func called " << getC() << " times" << std::endl;
}

int main(void)
{
    D d;
    int new_val;
    std::cin >> new_val;
    d.check(new_val);
}