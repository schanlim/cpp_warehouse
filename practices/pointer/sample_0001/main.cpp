#include <iostream>

class Car
{
public:
    void Go() { std::cout << "Car Go" << std::endl; }
    ~Car() { std::cout << "Car Delete" << std::endl; }
};

// 스마트 포인터
template<typename T>
class Ptr
{
private:
    T* obj;
public:
    Ptr(T *p)
        : obj(p) {}
    T* operator->() {return obj;}
    T& operator*() {return *obj;}
    ~Ptr() {delete obj;}
};

int main(int, char**) {
    Car *c = new Car;
    c->Go();
    delete c;

    Ptr<Car> p = new Car; // Ptr p( new Car ) 로 생각하세요.
    p->Go();// ( p.operator->())Go() 의 모양이지만
            // ( p.operator->())->Go()로 해석됩니다.

    (*p).Go();

    return 1;
}
