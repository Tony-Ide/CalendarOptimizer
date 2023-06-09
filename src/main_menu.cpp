#include "../header/main_menu.hpp"
#include "../header/scheduler.hpp"
#include "../header/date.hpp"
#include "../header/event.hpp"
#include "../header/task.hpp"
#include "../header/todo.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <typeinfo>
using namespace std;


    MainMenu::MainMenu(Scheduler* schedule){
        scheduler=schedule;
   
    }
    MainMenu::~MainMenu()
    {
        delete scheduler;
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
    }

    void MainMenu::printWeek(){
        
        printf("Enter Date (e.g. 02 24 for February 24th): ");
        int month=0;
        int day=0;
        cin >> month >> day;

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
                        && (*todoIterater)->getTime() >= hour * 50 && (*todoIterater)->getTime() < hour*50 + 30 && typeid((*todoIterater)).name() != "BlackOutTime"){
                            
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

    void MainMenu::printDay(){
        /*int month = targetDate->getMonth();
        int day = targetDate->getMonth();
        */
        printf("Enter Date (e.g. 02 24 for February 24th): ");
        int month=0;
        int day=0;
        cin >> month >> day;

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
                && (*todoIterater)->getTime() >= hour*50 && (*todoIterater)->getTime() < hour*50 + 30 && typeid((*todoIterater)).name() != "BlackOutTime"){
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
    
    void  MainMenu::addTaskMenu(){

        int todoType;
        cout<<"Select option:"<<"\n"<<"1: Task (can be completed in multiple sessions)"<<"\n"<<"2: Event (must be completed in one sitting)"<<"\n"<<"3: Blackout (times you don't want any tasks scheduled)"<<"\n"<<endl;
        cout << "> ";
        cin>>todoType;

        if(todoType==1){
            int month;
            int day;
            string newTodoName;
            int priority;
            int time;
            int durationTime;
            cout<< "Enter Date (e.g. 02 24 for February 24th): ";
            cin>>month;
            cin>>day;
            cout<< "Enter Task Name: ";
            cin>>newTodoName;
            cout<< "Enter priority number (1 Least important - 3 Most Important): ";
            cin>>priority;
            cout<< "Enter duration time in hours: ";
            cin>>durationTime;
            cout<< "Enter start time (e.g. 1300 for 1:00pm): ";
            cin>>time;
            Date* newDate = new Date(month,day);
            Task* newTask = new Task(newDate, newTodoName, priority, time, durationTime);
            char choice;
            cout << "Would you like to add an alternative start time? (y or n): ";
            cin >> choice;
            if(choice == 'y')
            {
                cout<< "Enter alternate start time (e.g. 1300 for 1:00pm): ";
                cin>>time;
                newTask->addTime(time);
                cout << "Would you like to add another alternative start time? (y or n): ";
                cin >> choice;
                if(choice == 'y')
                {
                    cout<< "Enter alternate start time (e.g. 1300 for 1:00pm): ";
                    cin>>time;
                    newTask->addTime(time);
                }
            }
            scheduler->addTask(newTask);
        }

        else if(todoType==2){
            int month;
            int day;
            string newTodoName;
            int priority;
            int time;
            int durationTime;
            int repeat;
            cout<< "Enter Date (e.g. 02 24 for February 24th): ";
            cin>>month;
            cin>>day;
            cout<< "Enter Task Name: ";
            cin>>newTodoName;
            cout<< "Enter priority number (1 Least important - 3 Most Important): ";
            cin>>priority;
            cout<< "Enter duration time in hours: ";
            cin>>durationTime;
            cout << "How many days will this event repeat? (0 if it does not repeat): ";
            cin >> repeat;
            cout<< "Enter start time (e.g. 1300 for 1:00pm): ";
            cin>>time;
            Date* newDate = new Date(month,day);
            Event* newEvent = new Event(newDate, newTodoName, priority, time, durationTime, repeat);
            char choice;
            cout << "Would you like to add an alternative start time? (y or n): ";
            cin >> choice;
            if(choice == 'y')
            {
                cout<< "Enter alternate start time (e.g. 1300 for 1:00pm): ";
                cin>>time;
                newEvent->addTime(time);
                cout << "Would you like to add another alternative start time? (y or n): ";
                cin >> choice;
                if(choice == 'y')
                {
                    cout<< "Enter alternate start time (e.g. 1300 for 1:00pm): ";
                    cin>>time;
                    newEvent->addTime(time);
                }
            }
            scheduler->addTask(newEvent);
        }
        else if(todoType == 3)
        {
            int month;
            int day;
            int durationTime;
            int time;
            string taskname = "Blackout";
            int priority = 4;
            int repeat = 365;
            cout<< "Enter Date (e.g. 02 24 for February 24th): ";
            cin>>month;
            cin>>day;
            cout<< "Enter duration time in hours: ";
            cin>>durationTime;
            cout<< "Enter start time (e.g. 1300 for 1:00pm): ";
            cin>>time;
            Date* newDate = new Date(month,day);
            BlackOutTime* blackout = new BlackOutTime(newDate, taskname, priority, time, durationTime, repeat);
            scheduler->addTask(blackout);
        }
        else
        {
            cout << "Invalid Type! Aborting..." << endl;
        }
    }


    void  MainMenu::editTaskMenu(){
        int choice;
        printTaskList();
        cout << "Which task would you like to edit? ";
        cin >> choice;
        list<Todo*>::iterator it;
        it = scheduler->getTaskList().begin();
        for(int i = 1; i < choice; i++)
        {
            ++it;
        }
        int todoType;
        cout<<"Select option:"<<"\n"<<"1: Task (can be completed in multiple sessions)"<<"\n"<<"2: Event (must be completed in one sitting)"<<"\n"<<endl;
        cin>>todoType;
        if(todoType==1){
            int month;
            int day;
            string newTodoName;
            int priority;
            int time;
            int durationTime;
            cout<< "Enter New Date (e.g. 02 24 for February 24th): ";
            cin>>month;
            cin>>day;
            cout<< "Enter New Task Name: ";
            cin>>newTodoName;
            cout<< "Enter new priority number (1 Least important - 3 Most Important): ";
            cin>>priority;
            cout<< "Enter new duration time in hours: ";
            cin>>durationTime;
            cout<< "Enter new start time (e.g. 1300 for 1:00pm): ";
            cin>>time;
            Date* newDate = new Date(month,day);
            Task* newTask = new Task(newDate, newTodoName, priority, time, durationTime);
            char choice;
            cout << "Would you like to add an alternative start time? (y or n): ";
            cin >> choice;
            if(choice == 'y')
            {
                cout<< "Enter alternate start time (e.g. 1300 for 1:00pm): ";
                cin>>time;
                newTask->addTime(time);
                cout << "Would you like to add another alternative start time? (y or n): ";
                cin >> choice;
                if(choice == 'y')
                {
                    cout<< "Enter alternate start time (e.g. 1300 for 1:00pm): ";
                    cin>>time;
                    newTask->addTime(time);
                }
            }
            scheduler->editTask(*it, newTask);
            cout << endl;
            cout << "Task edited successfully." << endl;
        }

        else if(todoType==2){
            int month;
            int day;
            string newTodoName;
            int priority;
            int time;
            int durationTime;
            int repeat;
            cout<< "Enter New Date (e.g. 02 24 for February 24th): ";
            cin>>month;
            cin>>day;
            cout<< "Enter New Task Name: ";
            cin>>newTodoName;
            cout<< "Enter new priority number (1 Least important - 3 Most Important): ";
            cin>>priority;
            cout<< "Enter new duration time in hours: ";
            cin>>durationTime;
            cout << "How many days will this event repeat? (0 if it does not repeat): ";
            cin >> repeat;
            cout<< "Enter new start time (e.g. 1300 for 1:00pm): ";
            cin>>time;
            Date* newDate = new Date(month,day);
            Event* newEvent = new Event(newDate, newTodoName, priority, time, durationTime, repeat);
            char choice;
            cout << "Would you like to add an alternative start time? (y or n): ";
            cin >> choice;
            if(choice == 'y')
            {
                cout<< "Enter alternate start time (e.g. 1300 for 1:00pm): ";
                cin>>time;
                newEvent->addTime(time);
                cout << "Would you like to add another alternative start time? (y or n): ";
                cin >> choice;
                if(choice == 'y')
                {
                    cout<< "Enter alternate start time (e.g. 1300 for 1:00pm): ";
                    cin>>time;
                    newEvent->addTime(time);
                }
            }
            scheduler->editTask(*it, newEvent);
            cout << endl;
            cout << "Task edited successfully." << endl;
        }
        else
        {
            cout << "Invalid Type! Aborting..." << endl;
        }
    }

    void MainMenu::deleteTaskMenu()
    {
        int choice;
        printTaskList();
        cout << "Which task would you like to delete? ";
        cin >> choice;
        while(cin.fail())
        {
            cout << "Please enter the task number." << endl;
            cin.clear();
            cin.ignore(10000,'\n');
            cin >> choice;
        }
        list<Todo*>::iterator it;
        it = scheduler->getTaskList().begin();
        for(int i = 1; i < choice; i++)
        {
            ++it;
        }
        scheduler->removeTask(*it);
        cout << endl;
        cout << "Task removed successfully." << endl;
    }

    void MainMenu::organizeTasksMenu()
    {
        scheduler->optimize();
        cout << "Schedule has been optimized." << endl;
    }