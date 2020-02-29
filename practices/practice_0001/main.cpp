#include <iostream>

class Base
{
public:
    Base() { std::cout<<"Base()\n"; }
    Base(int a) { std::cout<<"Base(int)\n"; }
    ~Base() { std::cout<<"~Base()\n"; }
};

class Derived : public Base
{
public:
    Derived() { std::cout<<"Derived()\n"; }
    Derived(int a) { std::cout<<"Derived(int)\n"; }
    ~Derived() { std::cout<<"~Derived()\n"; }
};

int main(int, char**) {
    Derived d1(5);

    return 1;
}
