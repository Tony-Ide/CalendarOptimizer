#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP
#include "todo.hpp"
#include "blackout_time.hpp"
#include "date.hpp"
#include <list>

class Scheduler{
    private:
        list<Todo*> TaskList;
    public:
        void addTask(Todo *task);
        void removeTask(Todo *task);
        void editTask(Todo *originalTask, Todo *editedTask);
        void optimize();
        list<Todo*> getTaskList();
};

#endif // SCHEDULER_HPP