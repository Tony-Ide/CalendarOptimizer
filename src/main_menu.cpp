#include "../header/main_menu.hpp"
#include "../header/scheduler.hpp"
#include "../header/date.hpp"
//#include "../header/event.hpp"
#include "../header/todo.hpp"
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
    vector<string> split(string input, char delimiter) {
        vector<string> answer;
        stringstream ss(input);
        string temp;
    
        while (getline(ss, temp, delimiter)) {
            answer.push_back(temp);
        }
        return answer;
    }

    MainMenu::MainMenu(Scheduler* schedule){
        scheduler=schedule;
   
    }
    void MainMenu::printCalendar() {
        // Implementation goes here
    }


    void MainMenu::printWeek(string date){

    }
    void MainMenu::printDay(std::string date){

        vector<string> dateSplit = split(date,'/');
        int month = stoi(dateSplit[0]);
        int day = stoi(dateSplit[1]);
        list<Todo*> newTodoList = scheduler->getTaskList();
        list<Todo*>::iterator todoIterater;

        bool NotconsecutiveTodo =false;
        int lastLineNum=0;
        int printline=0;
        int todoExists=false;
        for(int hour=5*2;hour<25*2;hour++){
            for(todoIterater = newTodoList.begin(); todoIterater!= newTodoList.end(); todoIterater++){
                if((*todoIterater)->getDate()->getMonth() == month && (*todoIterater)->getDate()->getDay() == day
                && (*todoIterater)->getTime() >= hour*50 && (*todoIterater)->getTime() < hour*50 + 30){
                    printline = (*todoIterater)->getDuration()*2+1;
                    lastLineNum= hour+printline;
                    for(int line = 0;line<printline-1;line++){
                        if(NotconsecutiveTodo == true){
                            if(line%2 == 0){printf("| %2i:00 |",hour/2+line/2);}
                            else {printf("|       |");}
                        }
                        else{
                            continue;
                        }
                        if(line == 0){
                            printf("-------------|\n");
                        }
                        else if(line == printline/2){
                            printf("%9s    |\n", (*todoIterater)->getName().c_str());
                        }
                        else{
                            printf("             |\n");
                        }
                    }
                    hour = lastLineNum-1;
                    todoExists = true;
                } 
            }
            if(todoExists == false){
                if(hour%2 ==0){printf("| %2i:00 |             |",hour/2);}
                else {printf("|       |             |");}
                NotconsecutiveTodo = true;
            }
            else{
                if(hour%2 ==0){printf("| %2i:00 |",hour/2);}
                else {printf("|        |");}
                printf("-------------|");
            }
            printf("\n");
            todoExists = false;
        }
        printf("|---------------------|\n");

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
            int month;
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
            int month;
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