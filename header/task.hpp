#ifndef TASK_HPP
#define TASK_HPP
#include "todo.hpp"

class Task: public Todo{
    private:


    public:
    Task(Date* d, string s, int p, int t, int dur);
    void splitTask(Task* newTask);
};

#endif // TASK_HPP