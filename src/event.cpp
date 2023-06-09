#include "../header/event.hpp"

Event::Event()
{
    priority = 0;
}
Event::Event(Date* d, string s, int p, int t, int dur, int r)
{
    date = d;
    name = s;
    priority = p;
    time.push_back(t);
    duration = dur;
    repeat = r;
}