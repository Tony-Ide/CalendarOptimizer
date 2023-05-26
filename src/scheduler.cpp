#include "../header/scheduler.hpp"
#include <iostream>
#include <string.h>
#include <list>
#include <iterator>

using namespace std;
Scheduler::Scheduler(){
    

}
void Scheduler::addTask(Todo *task)
{
   
}

void Scheduler::removeTask(Todo *task)
{

}

void Scheduler::editTask(string taskName, Todo *editedTask)
{
    int i = 0;
    list<Todo*>::iterator it;
    for(it = taskList.begin(); it != taskList.end(); ++it)
    {
        if((*it) -> getName() == taskName)
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