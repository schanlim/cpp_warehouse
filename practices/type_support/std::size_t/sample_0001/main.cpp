#include <cstddef>
#include <iostream>
#include <array>
 
int main()
{
    std::array<std::size_t, 10> a;
    for (std::size_t i = 0; i != a.size(); ++i)
        a[i] = i;
    for (std::size_t i = a.size()-1; i < a.size(); --i)
        std::cout << a[i] << " ";
}