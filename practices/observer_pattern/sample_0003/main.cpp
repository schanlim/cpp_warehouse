#include <iostream>
#include <functional>
#include <map>
#include <vector>

class NotificationCenter
{
private:
    typedef std::function<void()> HANDLER;
    std::map<std::string, std::vector<HANDLER>> noti_map;
public:
    void addObserver(std::string key, HANDLER handler) {
        noti_map[key].push_back(handler);
    }

    void postNotificationWithName(std::string key) {
        std::vector<HANDLER> &v = noti_map[key];
        for (int i = 0; i < v.size(); i++) {
            v[i]();
        }
    }

    static NotificationCenter &defaultCenter() {
        static NotificationCenter center;
        return center;
    }
};

void foo() {
    std::cout << "foo" << std::endl;
}

void goo(int a) {
    std::cout << "goo: " << a << std::endl;
}

int main(int, char**) {
    //NotificationCenter nc;
    NotificationCenter &nc = NotificationCenter::defaultCenter(); // like singleton
    nc.addObserver("LOWBATTERY", &foo);
    nc.addObserver("LOWBATTERY", std::bind(&goo, 5));

    nc.postNotificationWithName("LOWBATTERY");

    return 1;
}
