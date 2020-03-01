#include "person.h"
#include "chatroom.h"

Person::Person(const std::string& name) : name(name)
{
}

void Person::receive(const std::string& origin, const std::string& message) {
    std::string s{ origin + ": \"" + message + "\"" };
    std::cout << "[" << name << "'s chat session]" << s << "\n";
    chat_log.emplace_back(s);
}

void Person::say(const std::string& message) const {
    room->broadcase(name, message);
}

void Person::pm(const std::string& who, const std::string& message) const {
    room->message(name, who, message);
}