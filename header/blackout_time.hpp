#ifndef BLACKOUT_TIME_HPP
#define BLACKOUT_TIME_HPP
#include <string>
#include "date.hpp"
#include "event.hpp"


class BlackOutTime : public Event{
    private:
        
    public:

        BlackOutTime(Date* d, string n, int p, int t, int dur, int r);

};

#endif // BLACKOUT_TIME_HPP