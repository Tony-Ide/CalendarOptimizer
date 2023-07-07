#include "../header/blackout_time.hpp"

#include <string>

BlackOutTime::BlackOutTime(Date* d, string n, int p, int t, int dur, int r){
    date = d;
    name = n;
    time.push_back(t);
    priority = p;
    duration = dur;
    repeat = r;
}

BlackOutTime::~BlackOutTime()
{
   
}

