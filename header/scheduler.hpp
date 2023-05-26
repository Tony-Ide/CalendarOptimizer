#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP
#include "todo.hpp"
// #include "blackout_time.hpp"
#include "date.hpp"
#include <list>
using namespace std;


class Scheduler{
    private:
        list<Todo*> taskList;
        // list<BlackoutTime*> BlackoutTimeList;
    public:
        Scheduler();
        void addTask(Todo *task);
        void removeTask(Todo *task);
        void editTask(string taskName, Todo *editedTask);
        void optimize();
};

#endif // SCHEDULER_HPP