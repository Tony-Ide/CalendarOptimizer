#include "../header/scheduler.hpp"
#include <iostream>
#include <string.h>
#include <list>
#include <iterator>

using namespace std;

void Scheduler::addTask(Todo *task)
{
    list<Todo*>::iterator it;
    bool conflict_detected = false;
    for(it = TaskList.begin(); it != TaskList.end(); ++it)
    {
        if((*it)->getDate()->getMonth() == task->getDate()->getMonth() && (*it)->getDate()->getDay() == task->getDate()->getDay())
        {
            if(task->getTime() >= (*it)->getTime() && task->getTime() < ((*it)->getTime() + (*it)->getDuration()))
            {
                conflict_detected = true;
                if((*it)->getPriority() > task->getPriority())
                {
                    cout << "Conflict detected: Replacing " << (*it)->getName() << " task with " << task->getName() << "task." << endl;
                    cout << "Please reschedule " << (*it)->getName() << "task." << endl;
                    removeTask(*it);
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
    list<Todo*>::iterator it;
    for(it = TaskList.begin(); it != TaskList.end(); ++it)
    {
        if((*it)->getName() == task->getName())
        {
            break;
        }
    }
    TaskList.erase(it);
}

void Scheduler::editTask(string taskname, Todo *editedTask)
{
    list<Todo*>::iterator it;
    for(it = TaskList.begin(); it != TaskList.end(); ++it)
    {
        if((*it)->getName() == taskname)
        {
            break;
        }
    }
    TaskList.erase(it);
    TaskList.push_back(editedTask);
}

void Scheduler::optimize()
{
    
}