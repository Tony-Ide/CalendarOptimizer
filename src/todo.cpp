#include "../header/todo.hpp"
#include <vector>

using namespace std;

Date* Todo::getDate()
{
    return date;
}

string Todo::getName()
{
    return name;
}

int Todo::getPriority()
{
    return priority;
}

int Todo::getTime()
{
    return time.front();
}

int Todo::getDuration()
{
    return duration;
}
 void Todo::addTime(int t)
 {
    time.push_back(t);
 }