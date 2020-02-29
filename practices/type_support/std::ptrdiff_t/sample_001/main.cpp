#include <cstddef>
#include <iostream>
int main()
{
    const std::size_t N = 100;
    int* a = new int[N];
    int* end = a + N;

    for (std::ptrdiff_t i = N; i > 0; --i) {
        std::cout << (*(end - i) = i) << ' ';
    }

    std::cout << *(end - N)<< std::endl;

    delete[] a;
}