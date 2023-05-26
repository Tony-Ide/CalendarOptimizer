#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP
#include "todo.hpp"
#include "blackout_time.hpp"
#include "date.hpp"

class {
    private:
        list<Todo*> TaskList;
        list<BlackoutTime*> BlackoutTimeList;
    public:
        void addTask(Todo *task);
        void removeTask(Todo *task);
        void editTask(Todo *task);
        void optimize();
};

#endif // SCHEDULER_HPP