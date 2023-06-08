#ifndef TODO_HPP
#define TODO_HPP
#include "date.hpp"
#include <string.h>
#include <vector>

using namespace std;

class Todo{
    protected:
        Date* date;
        string name;
        int priority;
        vector<int> time;
        int duration;
    public:
        Date* getDate();
        string getName();
        int getPriority();
        int getTime();
        int getDuration();
        void addTime(int t);
};

#endif // TODO_HPP