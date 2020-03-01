#include "person.h"
#include "chatroom.h"
#include <algorithm>

void ChatRoom::join(Person *p) {
    std::string join_msg = p->name + "joins the chat.";
    broadcase("room", join_msg);
    p->room = this;
    people.push_back(p);
}

void ChatRoom::broadcase(const std::string& origin, const std::string& message) {
    for (auto p : people) {
        if (p->name != origin) {
            p->receive(origin, message);
        }
    }
}

void ChatRoom::message(const std::string& origin, const std::string& who, 
            const std::string& message) {
    auto target = std::find_if(begin(people), end(people),
                            [&](const Person* p) { 
                                return p->name == who;
                            });
    if (target != end(people)) {
        (*target)->receive(origin, message);
    }
}