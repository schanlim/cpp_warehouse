#pragma once

struct ChatRoom
{
    std::vector<Person*> people;

    void join(Person *p);
    void broadcase(const std::string& origin, const std::string& message);
    void message(const std::string& origin, const std::string& who, 
                const std::string& message);
};