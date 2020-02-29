// Composite 패턴
// 복합객체 ( PopupMenu ) 는 개별객체 ( MenuItem ) 뿐 아니라 복합객체 자신도 보관한다.
// 복합객체는 동일한 부모가 있어야 하며, 복합객체와 개별객체는 사용법이 동일하다. 또한 사용법은 부모에 있어야 한다.
// ( 재귀적 포함을 사용하는 디자인패턴 )

#include <iostream>
#include <vector>

class BaseMenu
{
private:
    std::string title;

public:
    BaseMenu(std::string s)
        : title(s) {}
    std::string getTitle() { return title; }
    virtual void command() = 0;
};

class PopupMenu : public BaseMenu
{
private:
    std::vector<BaseMenu *> v; // <<--- Composite pattern의 핵심

public:
    PopupMenu(std::string s)
        : BaseMenu(s) {};
    
    void addMenu(BaseMenu *p) {
        v.push_back(p);
    }

    virtual void command() override {
        while (1) {
            int sz = v.size();
            for (int i = 0; i < sz; i++) {
                std::cout << i + 1 << "." << v[i]->getTitle() << std::endl;
            }
            std::cout << sz + 1 << ".Go to upper menu" << std::endl;
            std::cout << "Select the item. >";
            int cmd;
            std::cin >> cmd;

            if (cmd < 1 || cmd > sz) continue;
            if (cmd == sz + 1) break;

            v[cmd - 1]->command();
        }
    }
};

class MenuItem : public BaseMenu
{
private:
    int id;

public:
    MenuItem(std::string s, int n)
        : BaseMenu(s), id (n) {}
    
    virtual void command() override {
        std::cout << getTitle() << " is selected." << std::endl;
    }
};

int main(int, char**) {
    PopupMenu *menubar = new PopupMenu("MenuBar");
    PopupMenu *p1 = new PopupMenu("Screen Configuration");
    PopupMenu *p2 = new PopupMenu("Sound Configuration");

    menubar->addMenu(p1);
    menubar->addMenu(p2);

    p1->addMenu(new MenuItem("Change resolution", 11));
    p1->addMenu(new MenuItem("Change color", 12));
    p2->addMenu(new MenuItem("Change volume", 21));
    p2->addMenu(new MenuItem("Change color of volume", 22));

    menubar->command();
}
