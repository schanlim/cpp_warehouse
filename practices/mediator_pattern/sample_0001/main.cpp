#include <iostream>

struct IMediator
{
    virtual void changeState(std::string n, std::string e) = 0;
    virtual ~IMediator() {}
};

class CheckBox
{
private:
    bool value;
    IMediator* pMediator;
public:
    CheckBox()
        : value(false) {}

    void setCheck(bool b) {
        value = b;
        changeState();
    }

    bool getCheck() { return value; }

    virtual void changeState() {
        pMediator->changeState("CheckBox", "change");
    }

    void setMediator(IMediator *p) {
        pMediator = p;
    }
};

class Radio
{
private:
    bool value;
    IMediator* pMediator;

public:
    Radio()
        : value(false) {}

    void setCheck(bool b) {
        value = b;
        changeState();
    }

    bool getCheck() { return value; }

    virtual void changeState() {
        pMediator->changeState("Radio", "change");
    }

    void setMediator(IMediator *p) {
        pMediator = p;
    }
};

class Slider
{
private:
    bool value;
    IMediator* pMediator;

public:
    Slider()
        : value(false) {}

    void setCheck(bool b) {
        value = b;
        changeState();
    }

    bool getCheck() { return value; }

    virtual void changeState() {
        pMediator->changeState("Slider", "change");
    }

    void setMediator(IMediator *p) {
        pMediator = p;
    }
};

class LoginMediator : public IMediator
{
private:
    CheckBox& c;
    Radio& r;
    Slider& s;

public:
    LoginMediator(CheckBox& _c, Radio& _r, Slider& _s)
        : c(_c), r(_r), s(_s) {
            c.setMediator(this);
            r.setMediator(this);
            s.setMediator(this);
        }
    
    void changeState(std::string name, std::string ev) {
        if (c.getCheck() == true && r.getCheck() == true && s.getCheck() == true) {
            std::cout << "Button enabled.\n";
        } else {
            std::cout << "Button disabled.\n";
        }
    }
};

int main(int, char**) {
    CheckBox c;
    Radio r;
    Slider s;

    LoginMediator m(c, r, s);
    c.setCheck(true);
    r.setCheck(true);
    s.setCheck(true);

    r.setCheck(false);
}
