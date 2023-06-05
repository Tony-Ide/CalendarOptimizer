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
        //if the user input is "help", this function will be called
    //this function opens the help screen
        string command;
        cout<<"Manage Tasks Help"<<"\n"<<"\n";
        cout<<"Add           "<<"add schedule on"<<"\n";
        cout<<"Delete        "<<"delete schedule for the"<<"\n";
        cout<<"Edit          "<<"edit added schedule on"<<"\n";
        cout<<"Organize      "<<"organize schedule automatically base on added schedule"<<"\n"<<"\n";
        cout<<"Use --help to find out more about commands such as Add --help"<<"\n";
        cout<<"Enter exit to exit help screen"<<"\n"<<"\n";

        while(command != "exit"){
            cout<<"Enter command >> ";
            cin>>command;

            if(command == "Add --help"){
                //implement how to use Add
            }
            else if(command == "Delete --help"){
                //implement how to use Delete
            }
            else if(command == "Edit --help"){
                //implement how to use Edit
            }
            else if(command == "Organize --help"){
                //implement how to use Organize
            }
        }
        return 0;
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