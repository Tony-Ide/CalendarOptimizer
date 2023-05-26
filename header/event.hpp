#include "todo.hpp"
#ifndef EVENT_HPP
#define EVENT_HPP

class Event: public Todo{
    private:



    public:
    Event(int r, Date* d, string n, int p, int t, int dur);
    int recall;


};

#endif // EVENT_HPP