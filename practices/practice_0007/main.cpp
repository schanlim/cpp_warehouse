#include <iostream>

template <typename T>
void MySort(int *x, int n, T cmp) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cmp(x[i], x[j]))
                std::swap(x[i], x[j]);
        }
    }
};

struct Less
{
    inline bool operator()(int a, int b) {
        return a < b;
    }

};

struct Greater
{
    inline bool operator()(int a, int b) {
        return a > b;
    }

};

inline bool cmp1(int a, int b) { return a > b; }
inline bool cmp2(int a, int b) { return a < b; }

int main(int, char**) {
    int x[10] = { 2, 3, 5, 10, 9, 3, 890, 2, 1 , 76};

    Less f1;    // operator()를 사용하면 inline이 적용이 되어야 속도 빠름, but code size 증가
    Greater f2; // operator()를 사용하면 inline이 적용이 되어야 속도 빠름, but code size 증가

    MySort(x, 10, f1); // operator()를 사용하면 inline이 적용이 되어야 속도 빠름, but code size 증가
    for (int i = 0; i < 10; i++)
        std::cout << x[i] << ' ';
    std::cout << std::endl;

    MySort(x, 10, f2); // operator()를 사용하면 inline이 적용이 되어야 속도 빠름, but code size 증가
    for (int i = 0; i < 10; i++)
        std::cout << x[i] << ' ';
    std::cout << std::endl;

    MySort(x, 10, cmp2); // function pointer는 inline이 적용이 되지 않고, inline function도 function call이 됨. 속도 저하.
    for (int i = 0; i < 10; i++)
        std::cout << x[i] << ' ';
    std::cout << std::endl;

    MySort(x, 10, cmp1); // function pointer는 inline이 적용이 되지 않고, inline function도 function call이 됨. 속도 저하.
    for (int i = 0; i < 10; i++)
        std::cout << x[i] << ' ';
    std::cout << std::endl;
}
