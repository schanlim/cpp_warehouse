#include <iostream>
#include <vector>
#include <cstring>

#define interface struct

interface IGraph
{
    virtual void onUpdate(int *data) = 0;
    virtual ~IGraph() {}
};

class PieGraph : public IGraph
{
private:
public:
    virtual void onUpdate(int *data) override {
        std::cout << "********* PieGraph ************" << std::endl;
        for (int i = 0; i < 5; i++) {
            std::cout << i << ":" << data[i] << std::endl;
        }
    }
};

class BarGraph : public IGraph
{
private:
public:
    virtual void onUpdate(int *data) override {
        std::cout << "********* BarGraph ************" << std::endl;
        for (int i = 0; i < 5; i++) {
            std::cout << i << ":" << data[i] << std::endl;
        }
    }
};

class Table
{
private:
    std::vector<IGraph *> v;
    int data[5];
public:
    Table() {
        std::memset(data, 0, sizeof(data));
    }

    void attach(IGraph *p) {
        v.push_back(p);
    }

    void detach(IGraph *p) {}

    void notify(int *d) {
        for (int i = 0; i < v.size(); i++) {
            v[i]->onUpdate(d);
        }
    }

    void edit() {
        //while(1) {
            int index;
            std::cout << "index >> ";
            std::cin >> index;
            std::cout << "data >> ";
            std::cin >> data[index];
            std::getchar();
            notify(data);
        //}
    }
};

int main(int, char**) {
    Table t;
    BarGraph bg;
    t.attach(&bg);
    PieGraph pg;
    t.attach(&pg);
    t.edit();
    return 0;
}
