#ifndef EVENT_HPP
#define EVENT_HPP
#include "todo.hpp"

class Event: public Todo{
    protected:
        int repeat;

    public:
    Event();
    Event(Date* d, string s, int p, int t, int dur, int r);
};

#endif // EVENT_HPP