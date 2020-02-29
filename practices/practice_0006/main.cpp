#include <iostream>

class Base1
{
public:
    Base1() {std::cout << "Base1()\n"; }
    ~Base1() { std::cout << "~Base1()\n"; }
};

class Derived1 : public Base1
{
public:
    Derived1() { std::cout << "Derived1()\n"; }
    ~Derived1() { std::cout << "~Derived1()\n"; }
};

class Base2
{
public:
    Base2() {std::cout << "Base2()\n"; }
    virtual ~Base2() { std::cout << "~Base2()\n"; }
};

class Derived2 : public Base2
{
public:
    Derived2() { std::cout << "Derived2()\n"; }
    ~Derived2() { std::cout << "~Derived2()\n"; }
};

int main(int, char**) {
    Base1 *p1 = new Derived1;
    delete p1; // ~Drived1() call되지 않음.

    std::cout << std::endl;

    Base2 *p2 = new Derived2;
    delete p2; // ~Drived2() call.
}
