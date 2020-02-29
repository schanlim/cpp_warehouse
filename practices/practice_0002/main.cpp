#include <iostream>
#include <deque>
#include <list>
#include <vector>

template<typename T, typename C = std::deque<T>>
class stack
{
private:
    C st;
public:
    inline void push(const T& a) { st.push_back(a); }
    inline T& top() { st.back(); }
    inline void pop() { st.pop_back(); }
};

int main(int, char**) {
    stack<int> s0;
    stack<int, std::list<int>> s1;
    stack<int, std::vector<int>> s2;

    s1.push(5);
    s1.push(6);
    std::cout << s1.top() << "\n";

    return 1;
}
