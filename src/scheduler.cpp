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
    for(it = this->taskList.begin(); it != this->taskList.end(); ++it)
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
                    this->taskList.push_back(task);
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
        this->taskList.push_back(task);
    }
}

void Scheduler::removeTask(Todo *task)
{
    int i = 0;
    list<Todo*>::iterator it;
    for(it = this->taskList.begin(); it != this->taskList.end(); ++it)
    {
        if((*it)->getName() == task->getName())
        {
            break;
        }
        i++;
    }
    this->taskList.erase(it);
}

void Scheduler::editTask(string taskName, Todo *editedTask)
{
    int i = 0;
    list<Todo*>::iterator it;
    for(it = this->taskList.begin(); it != this->taskList.end(); ++it)
    {
        if((*it) -> getName() == taskName)
        {
            break;
        }
        i++;
    }
    this->taskList.erase(it);
    this->taskList.push_back(editedTask);
}

void Scheduler::optimize()
{
    
}