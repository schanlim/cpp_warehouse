// 함수 바인딩
// Static Binding

#include <iostream>

class Animal
{
public:
    void Cry1() { std::cout << "Animal Cry1\n"; }
    void Cry2() { std::cout << "Animal Cry2\n"; }
    virtual void Cry3() { std::cout << "Animal Cry3\n"; }
    virtual void Cry4() { std::cout << "Animal Cry4\n"; }
};

class Dog : public Animal
{
public:
    void Cry1() { std::cout << "Dog Cry1\n"; }
    virtual void Cry2() { std::cout << "Dog Cry2\n"; }
    void Cry3() { std::cout << "Dog Cry3\n"; }
    virtual void Cry4() { std::cout << "Dog Cry4\n"; }
};

int main(int, char**) {
    std::cout << "Function Binding. Animal is Super class and Dog is Sub class.\n";
    Animal a;
    Dog d;
    std::cout << std::endl;

    std::cout << "Static bind : Upcasting\n";
    Animal *a1 = 0;
    a1 = &d; // upcasting : 서브클래스가 슈퍼클래스 타입으로 변경되는 것.
    a1->Cry1(); // Animal Cry1
    std::cout << std::endl;

    std::cout << "Static bind : Upcasting\n";
    Animal *a2 = 0;
    a2 = &d; // upcasting : 서브클래스가 슈퍼클래스 타입으로 변경되는 것.
    a2->Cry2(); // Animal Cry2
    std::cout << std::endl;

    std::cout << "Dynamic bind : Upcasting\n";
    Animal *a3 = 0;
    a3 = static_cast<Animal *>(&d); // upcasting : 서브클래스가 슈퍼클래스 타입으로 변경되는 것.
    a3->Cry3(); // Dog Cry3
    std::cout << std::endl;

    std::cout << "Dynamic bind : Upcasting\n";
    Animal *a4 = 0;
    a4 = &d; // upcasting : 서브클래스가 슈퍼클래스 타입으로 변경되는 것.
    a4->Cry4(); // Dog Cry4
    std::cout << std::endl;
}
