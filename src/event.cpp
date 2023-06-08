#include "../header/event.hpp"

Event::Event(Date* d, string s, int p, int t, int dur)
{
    date = d;
    name = s;
    priority = p;
    time.push_back(t);
    duration = dur;
}
