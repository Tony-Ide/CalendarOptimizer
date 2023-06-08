#ifndef BLACKOUT_TIME_HPP
#define BLACKOUT_TIME_HPP
#include <string>
#include "date.hpp"
#include "event.hpp"


class BlackOutTime : public Event{
    private:
        
    public:

        BlackOutTime(Date* d, int t, int dur);

};

#endif // BLACKOUT_TIME_HPP