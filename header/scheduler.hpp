#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP
#include "todo.hpp"
#include "blackout_time.hpp"
#include "date.hpp"
#include "task.hpp"
#include <list>

class Scheduler{
    private:
        list<Todo*> taskList;
        list<BlackoutTime*> BlackoutTimeList;
    public:
        void addTask(Todo *task);
        void removeTask(Todo *task);
        void editTask(string taskName, Todo *task);
        void optimize();
};

#endif // SCHEDULER_HPP