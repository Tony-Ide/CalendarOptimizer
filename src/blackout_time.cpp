#include "../header/blackout_time.hpp"

#include <string>

BlackOutTime::BlackOutTime(Date d, std::string n, int t) {
    date = d;
    name = n;
    time = t;
}

