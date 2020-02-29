// Composite Pattern

#include <iostream>
#include <vector>

class Data
{
private:
    std::string title;

public:
    Data(std::string s)
        : title(s) {}
    virtual int getSize() = 0;
};

class Folder : public Data
{
private:
    std::vector<Data *> v; // <<--- Composite pattern의 핵심

public:
    Folder(std::string s)
        : Data(s) {}

    virtual int getSize() override {
        int sz = 0;
        for (int i = 0; i < v.size(); i++) {
            sz += v[i]->getSize();
        }
        return sz;
    }

    void addItem(Data *p) {
        v.push_back(p);
    }
};

class File : public Data
{
private:
    int size;

public:
    File(std::string s, int n)
        : Data(s), size(n) {}
    
    virtual int getSize() override {
        return size;
    }
};

int main(int, char**) {
    Folder* root = new Folder("root");
    Folder* fo1 = new Folder("A");
    Folder* fo2 = new Folder("B");

    // 파일은 자신만의 크기가 있습니다.
    File* f1 = new File("a.txt", 10);
    File* f2 = new File("b.txt", 20);
    File* f3 = new File("c.txt", 30);

    root->addItem(fo1);
    fo1->addItem(fo2);
    fo2->addItem(f3);
    fo1->addItem(f2);
    root->addItem(f1);

    // 폳더는 자신의 크기는 없지만 크기를 구할 수 있습니다.
    std::cout << f1->getSize() << std::endl;        // 10
    std::cout << fo1->getSize() << std::endl;        // 50
    std::cout << root->getSize() << std::endl;        // 60
}
