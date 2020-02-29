// Observer pattern
// 하나의 이벤트를 등록된 여러 객체로 전달하는 패턴

#include <iostream>
#include <vector>

class IMenuListener
{
public:
    virtual void onCommand(int id) = 0;
    virtual ~IMenuListener() {}
};

class Camera : public IMenuListener
{
public:
    void onCommand(int id) override {
        switch(id)
        {
        case 11: break;
        case 12: break;
        }
        std::cout << "Camera onCommand" << std::endl;
    }
};

class MenuItem
{
private:
    int id;
    std::vector<IMenuListener *> v;
public:
    MenuItem(int n)
        : id(n) {}

    void addListener(IMenuListener *p) {
        v.push_back(p);
    }

    void command() {
        for (int i = 0; i < v.size(); i++) {
            v[i]->onCommand(id);
        }
    }
};

int main(int, char**) {
    Camera cam;

    MenuItem m1(11);
    MenuItem m2(12);

    m1.addListener(&cam);
    m2.addListener(&cam);

    m1.command();
}
