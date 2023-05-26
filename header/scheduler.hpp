#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP
#include "todo.hpp"
#include "blackout_time.hpp"
#include "date.hpp"
#include <list>

class Scheduler{
    private:
        list<Todo*> TaskList;
        //list<BlackoutTime*> BlackoutTimeList;
    public:
        void addTask(Todo *task);
        void removeTask(Todo *task);
        void editTask(string taskname, Todo *editedtask);
        void optimize();
};

#endif // SCHEDULER_HPP