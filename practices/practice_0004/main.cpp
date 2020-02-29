#include <iostream>

#define interface struct

interface ICamera
{
    virtual void take() = 0;
    virtual ~ICamera() {}
};

class Camera : public ICamera
{
public:
    Camera() { std::cout << "Camera()\n"; }
    ~Camera() { std::cout << "~Camera()\n"; }
    void take() {
        std::cout << "take a picture\n";
    }
};

class People
{
public:
    People() { std::cout << "People()\n"; }
    ~People() { std::cout << "~People()\n"; }
    void useCamera(ICamera *c) {
        c->take();
    }
};

int main(int, char**) {
    People p;
    Camera c;
    p.useCamera(&c);
}
