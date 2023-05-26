#ifndef TODO_HPP
#define TODO_HPP
#include "date.hpp"
#include <string.h>

using namespace std;

class Todo{
    private:
        Date* date;
        string name;
        int priority;
        int time;
        int duration;
    public:
        Todo(Date d, string s, int p, int t, int dur);
        Date getDate();
        string getName();
        int getPriority();
        int getTime();
        int getDuration();
};

#endif // TODO_HPP