#include "../header/task.hpp"

Task::Task(Date* d, string s, int p, int t, int dur)
{
    date = d;
    name = s;
    priority = p;
    time.push_back(t);
    duration = dur;
}

Task::~Task()
{
    delete date;
}
