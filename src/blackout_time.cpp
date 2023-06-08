#include "../header/blackout_time.hpp"

#include <string>

BlackOutTime::BlackOutTime(Date* d, int t, int dur) {
    date = d;
    name = "Blackout";
    time.push_back(t);
    priority = 4;
    duration = dur;
}

