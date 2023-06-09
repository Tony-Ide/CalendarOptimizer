#include "../header/scheduler.hpp"
#include <iostream>
#include <string.h>
#include <list>
#include <stack>
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
            if(task->getTime() >= (*it)->getTime() && task->getTime() < ((*it)->getTime() + ((*it)->getDuration() * 100)))
            {
                conflict_detected = true;
                if((*it)->getPriority() < task->getPriority())
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
            else if(task->getTime() < (*it)->getTime() && (task->getTime() + (task->getDuration() * 100)) > (*it)->getTime())
            {
                conflict_detected = true;
                if((*it)->getPriority() < task->getPriority())
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

void Scheduler::editTask(Todo *originalTask, Todo *editedTask)
{
    removeTask(originalTask);
    delete originalTask;
    addTask(editedTask);
}

void Scheduler::optimize()
{
    stack<Todo*> notProcessed;
    for(int i = 1; i <= 4; i++)
    {
        list<Todo*>::iterator it;
        for(it = TaskList.begin(); it != TaskList.end(); ++it)
        {
            if((*it)->getPriority() == i)
            {
                notProcessed.push(*it);
            }
        }
    }
    TaskList.clear();
    TaskList.push_back(notProcessed.top());
    notProcessed.pop();
    while(notProcessed.empty() == false)
    {
        list<Todo*>::iterator it;
        bool conflict_detected = false;
        for(it = TaskList.begin(); it != TaskList.end(); ++it)
        {
            if((*it)->getDate()->getMonth() == notProcessed.top()->getDate()->getMonth() && (*it)->getDate()->getDay() == notProcessed.top()->getDate()->getDay())
            {
                if(notProcessed.top()->getTime() >= (*it)->getTime() && notProcessed.top()->getTime() < ((*it)->getTime() + ((*it)->getDuration() * 100)))
                {
                    conflict_detected = true;
                    cout << "Conflict detected: Please reschedule " << notProcessed.top()->getName() << " task." << endl;
                    break;
                }
                else if (notProcessed.top()->getTime() < (*it)->getTime() && (notProcessed.top()->getTime() + (notProcessed.top()->getDuration() * 100)) > (*it)->getTime())
                {
                    conflict_detected = true;
                    cout << "Conflict detected: Please reschedule " << notProcessed.top()->getName() << " task." << endl;
                    break;
                }
            }
        }
        if(conflict_detected == false)
        {
            TaskList.push_back(notProcessed.top());
        }
        notProcessed.pop();
    }
}

list<Todo*> Scheduler::getTaskList(){
    return TaskList;
}
