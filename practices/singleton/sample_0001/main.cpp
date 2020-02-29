#include <iostream>
#include <typeinfo>

class Cursor
{
private:
    Cursor() {} // 규칙 1. private 생성자
    Cursor(const Cursor&) = delete; // 규칙2. 복사와 대입금지
    void operator=(const Cursor&) = delete; // 규칙2. 복사와 대입금지
public:
    // 규칙3. 오직 하나의 객체만 만들어서 리턴하는 static 함수
    static Cursor& getInstance() {
        static Cursor instance;
        return instance;
    }
};

int main(int, char**) {
    Cursor& c1 = Cursor::getInstance();
    Cursor& c2 = Cursor::getInstance();
}
