#include "../header/main_menu.hpp"
#include "../header/scheduler.hpp"
#include "../header/date.hpp"
//#include "../header/event.hpp"
#include "../header/todo.hpp"
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


    MainMenu::MainMenu(Scheduler* schedule){
        scheduler=schedule;
   
    }
    void MainMenu::printTaskList() {
        list<Todo*> newTodoList = scheduler->getTaskList();
        list<Todo*>::iterator todoIterater; 
        printf(" #        NAME      DUEDAY   STARTTIME  DURATiON  PRIORITY  \n");

        int number=1;
        for(todoIterater = newTodoList.begin(); todoIterater!= newTodoList.end(); todoIterater++){
            printf("%2i. %13s  %2i/%2i      %4i       %2i         %i\n",number,(*todoIterater)->getName().c_str(),(*todoIterater)->getDate()->getMonth(),(*todoIterater)->getDate()->getDay(), (*todoIterater)->getTime(),(*todoIterater)->getDuration(), (*todoIterater)->getPriority());
            number++;
        }

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

    void MainMenu::printWeek(Date* targetDate){
        /*vector<string> dateSplit = split(date,'/');
        int month = stoi(dateSplit[0]);
        int day = stoi(dateSplit[1]);*/
        int month = targetDate->getMonth();
        int day = targetDate->getMonth();
        int m[]= { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        vector<int> printdates[7];
        
        for(int i = -3; i<4;i++){
            if(day + i <= 0){
                if(month==1) printdates[i+3].push_back(12);
                else printdates[i+3].push_back(month-1);

                printdates[i+3].push_back(day+i+m[month-1]);
            }
            else if(day+i>m[month]){
                if(month == 12) printdates[i+3].push_back(1);
                else printdates[i+3].push_back(month+1);
                printdates[i+3].push_back(day+i-m[month]);
            }
            else{
                printdates[i+3].push_back(month);
                printdates[i+3].push_back(day+i);
            }
        }
        
        
        list<Todo*> newTodoList = scheduler->getTaskList();
        list<Todo*>::iterator todoIterater;
        vector<string> linePrint[7][51];//<printing Line>

        printf("|       |");
        for(int days=0;days<7;days++){
            printf("    %2i/%2i    |",printdates[days][0],printdates[days][1]);
        }
        printf("\n");
        for(int hour=6*2;hour<25*2;hour++){
            for(todoIterater = newTodoList.begin(); todoIterater!= newTodoList.end(); todoIterater++){
                for(int days=0;days<7;days++){
                    if((*todoIterater) ->getDate()->getMonth() == printdates[days][0] && (*todoIterater)->getDate()->getDay() == printdates[days][1]
                        && (*todoIterater)->getTime() >= hour * 50 && (*todoIterater)->getTime() < hour*50 + 30){
                            
                        for(int i=0;i<(*todoIterater)->getDuration()*2+1;i++){
                            if(hour+i > 50){
                                break;
                            }
                            if(i == 0|| i == (*todoIterater)->getDuration()*2){
                                if(linePrint[days][hour+i].size() == 0){
                                    linePrint[days][hour+i].push_back("-------------");
                                }
                            }
                            else if (i == ((*todoIterater)->getDuration()*2+1)/2){
                                linePrint[days][hour+i].push_back((*todoIterater)->getName());
                            }
                        }
                        
                    }
                }
            }
        }
        
        for(int hour=6*2;hour<25*2;hour++){
            if(hour%2 ==0){printf("| %2i:00 |",hour/2);}
            else {printf("|       |");}
            for(int days=0;days<7;days++){
                if(linePrint[days][hour].size() != 0){
                    for(int i=0;i<linePrint[days][hour].size();i++){
                        printf("%13s",linePrint[days][hour][i].c_str());
                    }
                    printf("|");
                }
                else{
                    printf("             |");
                }
            }
            printf("\n");
        }
        
    }

    void MainMenu::printDay(Date* targetDate){
        int month = targetDate->getMonth();
        int day = targetDate->getMonth();
        list<Todo*> newTodoList = scheduler->getTaskList();
        list<Todo*>::iterator todoIterater;

        bool NotconsecutiveTodo =false;
        int lastLineNum=0;
        int printline=0;
        int todoExists=false;
        printf("          %2i/%2i\n",month,day);
        for(int hour=6*2;hour<25*2;hour++){
            for(todoIterater = newTodoList.begin(); todoIterater!= newTodoList.end(); todoIterater++){
                if((*todoIterater)->getDate()->getMonth() == month && (*todoIterater)->getDate()->getDay() == day
                && (*todoIterater)->getTime() >= hour*50 && (*todoIterater)->getTime() < hour*50 + 30){
                    printline = (*todoIterater)->getDuration()*2+1;
                    lastLineNum= hour+printline;
                    for(int line = 0;line<printline-1;line++){
                        if(hour+line<50){
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
                    }
                    hour = lastLineNum-1;
                    todoExists = true;
                } 
            }
            if(lastLineNum<50){
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
            }

            todoExists = false;
        }
        printf("|---------------------|\n");
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
