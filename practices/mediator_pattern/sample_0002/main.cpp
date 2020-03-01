#include "person.h"
#include "chatroom.h"

int main(int, char**) {
    ChatRoom room;
    Person john{ "john" };
    Person jane{ "jane" };

    room.join(&john);
    room.join(&jane);

    john.say("hi room");
    jane.say("oh, hey join");

    Person simon("simon");
    room.join(&simon);
    simon.say("hi everyone!");

    jane.pm("simon", "glad you could join us, simon");
}
