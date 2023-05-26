#include "../header/scheduler.hpp"
#include <iostream>
#include <string.h>
#include <list>
#include <iterator>

using namespace std;

void Scheduler::addTask(Todo *task)
{
    list<Task*>::iterator it;
    bool conflict_detected = false;
    for(it = taskList.begin(); it != taskList.end(); ++it)
    {
        if(it->getDate()->getMonth() == task->getDate()->getMonth() && it->getDate()->getDay() == task->getDate()->getDay())
        {
            if(task->getTime() >= it->getTime() && task->getTime < (it->getTime() + it->getDuration()))
            {
                conflict_detected = true;
                if(it->getPriority() > task->getPriority())
                {
                    cout << "Conflict detected: Replacing " << it->getName() << " task with " << task->getName() << "task." << endl;
                    cout << "Please reschedule " << it->getName() << "task." << endl;
                    removeTask(it);
                    TaskList.push_back(task);
                }
                else
                {
                    cout << "Conflict detected: Please reschedule " << task->getName() << " task." << endl;
                }
                break;
            }
        }
    }
    if(conflict_detected == false)
    {
        TaskList.push_back(task);
    }
}

void Scheduler::removeTask(Todo *task)
{
    int i = 0;
    list<Todo*>::iterator it;
    for(it = taskList.begin(); it != taskList.end(); ++it)
    {
        if(it->getName() == task->getName())
        {
            break;
        }
        i++;
    }
    taskList.erase(i);
}

void Scheduler::editTask(Todo *task, Todo *editedTask)
{
    int i = 0;
    list<Task*>::iterator it;
    for(it = taskList.begin(); it != taskList.end(); ++it)
    {
        if(it->getName() == task->getName())
        {
            break;
        }
        i++;
    }
    taskList.erase(it);
    taskList.push_back(editedTask);
}

void Scheduler::optimize()
{
    
}