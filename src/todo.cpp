#include "../header/todo.hpp"

using namespace std;

Todo::Todo(Date* d, string s, int p, int t, int dur)
{
    date = d;
    name = s;
    priority = p;
    time = t;
    duration = dur;
}

Date Todo::getDate()
{
    return date;
}

string Todo::getName()
{
    return name;
}

int Todo::getPriority()
{
    return p;
}

int Todo::getTime()
{
    return time;
}

int Todo::getDuration()
{
    return duration;
}
