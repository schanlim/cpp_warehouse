#include <iostream>

class Camera
{
public:
    void take() {
        std::cout << "Camera take" << std::endl;
    }
};

void foo()
{
    std::cout << "foo" << std::endl;
}

class ICommand
{
public:
    virtual void Execute() = 0;
    virtual ~ICommand() {}
};

class FunctionCommand : public ICommand
{
private:
    typedef void (*HANDLER)();
    HANDLER handler;
public:
    FunctionCommand(HANDLER h)
        : handler(h) {}

    virtual void Execute() override {
        handler();
    }
};

template<typename T>
class MemberCommand : public ICommand
{
private:
    typedef void (T::*HANDLER)();
    HANDLER handler;
    T *target;
public:
    MemberCommand(HANDLER h, T *p)
        : handler(h), target(p) {}

    virtual void Execute() override {
        (target->*handler)();
    }
};

template<typename T>
MemberCommand<T>* cmd(void(T::*f)(), T* p) {
    return new MemberCommand<T>(f, p);
}


FunctionCommand *cmd(void(*f)()) {
    return new FunctionCommand(f);
}

int main(int, char**) {
    FunctionCommand fc(&foo);
    fc.Execute();

    ICommand *p = &fc;
    p->Execute();

    Camera cam;
    MemberCommand<Camera> mc(&Camera::take, &cam);
    mc.Execute();

    ICommand *p1 = &mc;
    p1->Execute();

    Camera cam1;
    ICommand *p2 = cmd(&Camera::take, &cam1);
    p2->Execute();

    ICommand *p3 = cmd(&foo);
    p3->Execute();
}
