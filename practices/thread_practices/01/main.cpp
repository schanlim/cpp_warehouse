#include <iostream>
#include <thread>
#include <chrono>

static void f1(int &n)
{
    n++;
}

class foo
{
public:
    void bar() {
        for (int i = 0; i < 5; i++) {
            ++n;
            std::cout << "thread 3 executing " << n << "\n";
        }
    }

    int n = 0;
};

class goo
{
public:
    void operator()() {
        for (int i = 0; i < 5; i++) {
            ++n;
            std::cout << "thread 4 executing " << n << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    int n = 0;
};

int main(int, char**) {
    int n = 0;
    foo f;
    goo g;

    std::thread t2(f1, std::ref(n));
    std::thread t3(&foo::bar, &f);
    std::thread t4(g);
    
    t2.join();
    t3.join();
    t4.join();

    std::cout << "number is " << n << "\n";
    std::cout << "number of f is " << f.n << "\n";
    std::cout << "number of g is " << g.n << "\n";
    
    return 1;
}
