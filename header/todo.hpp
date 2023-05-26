#ifndef TODO_HPP
#define TODO_HPP
#include "date.hpp"
using namespace std;

class Todo{
    private:


    protected:

    Date* date;
    string name; 
    int priority;
    int time;
    int durationTime;



    public:
    Todo(Date* d, string n, int p, int t, int dur);
    string getName();


};

#endif // TODO_HPP