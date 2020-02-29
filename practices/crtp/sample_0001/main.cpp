#include <iostream>

template <typename TYPE>
class Window
{
public:
    void msgLoop() {
        (static_cast<TYPE *>(this))->onClick();
        //onClick();
    }

    void onClick() {
        std::cout << "Window OnClick" << std::endl;
    }
};

class MyWindow : public Window<MyWindow>
{
public:
    void onClick() {
        std::cout << "MyWindow OnClick" << std::endl;
    }
};

int main(int, char**) {
    MyWindow w;
    w.msgLoop();
    return 0;
}
