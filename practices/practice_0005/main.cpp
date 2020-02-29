#include <iostream>
#include <stdio.h>
#include <conio.h>

#define interface struct

interface IValidator
{
    virtual bool validate(std::string s, char c) = 0;
    virtual bool isComplete(std::string s) { return true; }
};

class LineEdit
{
private:
    std::string data;
    IValidator *pVal;

public:
    LineEdit():pVal(0) {}
    void setValidator(IValidator *p) { pVal = p; }
    
    std::string getData() {
        data.clear();
        while(1) {
            char c = _getch();
            if (c == 13 && (pVal == 0 || pVal->isComplete(data))) break;
            if (pVal == 0 || pVal->validate(data, c)) {
                data.push_back(c);
                std::cout << c;
            }
        }
        std::cout << std::endl;

        return data;
    }
};

class LimitDigitValidator : public IValidator
{
private:
    size_t value;
public:
    LimitDigitValidator(int n)
        : value(n) {}

    virtual bool validate(std::string s, char c) override {
        return s.size() < value && isdigit(c);
    }

    virtual bool isComplete(std::string s) override {
        return s.size() == value;
    }
};

int main(int, char**) {
    LineEdit edit;
    LimitDigitValidator v(5);
    edit.setValidator(&v);
    while (1) {
        std::string s = edit.getData();
        std::cout << s << std::endl;
    }
}
 