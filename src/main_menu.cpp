#include "../header/main_menu.hpp"
#include "../header/scheduler.hpp"
#include "../header/date.hpp"
#include "../header/event.hpp"
#include "../header/todo.hpp"
#include <iostream>
using namespace std;


    MainMenu::MainMenu(Scheduler* schedule){
        scheduler=schedule;
   
    }
    void MainMenu::printCalendar() {
        // Implementation goes here
    }

    void MainMenu::printHelp() {
        // Implementation goes here
    }

    void MainMenu::printTaskTable() {
        // Implementation goes here
    }
    
    void  MainMenu::editTaskMenu(){
        string todoName;
        cout<<"Enter the task you want to edit: ";
        cin>>todoName;
        int todoType;
        cout<<"Select option:"<<"\n"<<"1: Normal Todo"<<"\n"<<"2: Recurring Todo"<<"\n"<<"3: Task Todo"<<"\n"<<endl;
        cin>>todoType;

        if(todoType==1){
            string month;
            int day;
            string newTodoName;
            int priority;
            int time;
            int durationTime;
            cout<< "Enter Month: ";
            cin>>month;
            cout<< "Enter Day: ";
            cin>>day;
            cout<< "Enter New Todo Name: ";
            cin>>newTodoName;
            cout<< "Enter priority number: ";
            cin>>priority;
            cout<< "Enter start time: ";
            cin>>time;
            cout<< "Enter duration time in hours: ";
            cin>>durationTime;
            Date* newDate = new Date(month,day);
            Todo* newTodo = new Todo(newDate, newTodoName, priority, time, durationTime);
            scheduler->editTask(todoName,newTodo);

        }

        else if(todoType==2){
            string month;
            int day;
            string newTodoName;
            int priority;
            int time;
            int durationTime;
            int recall;
            cout<< "Enter Month: ";
            cin>>month;
            cout<< "Enter Day: ";
            cin>>day;
            cout<< "Enter New Todo Name: ";
            cin>>newTodoName;
            cout<< "Enter priority number: ";
            cin>>priority;
            cout<< "Enter start time: ";
            cin>>time;
            cout<< "Enter duration time in hours: ";
            cin>>durationTime;
            cout<< "Enter how many weeks do you want to repeat this event for: ";
            cin>>recall;
            Date* newDate = new Date(month,day);
            //Event* newEvent = new Event(newDate, newTodoName, priority, time, durationTime);
            //scheduler->editTask(todoName,newEvent);

        }

        //write if statement for if user picks Task Todo

    }