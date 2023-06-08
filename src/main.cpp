#include <iostream>
#include "../header/main_menu.hpp"
#include "../header/scheduler.hpp"
using namespace std;

int main()
{
    Scheduler* hi = new Scheduler();
    MainMenu* m = new MainMenu(hi);
    int choice = 1;
    while(choice != 0)
    {
        cout << "1. Manage Tasks" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Help" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;
        if(choice == 1)
        {
            cout << "1. Add" << endl;
            cout << "2. Delete" << endl;
            cout << "3. Edit" << endl;
            cout << "4. Optimize" << endl;
            cout << "5. Back" << endl;
            cin >> choice;
            if(choice == 1)
            {
                m->addTaskMenu();
            }
            else if (choice == 2)
            {
                m->deleteTaskMenu();
            }
            else if (choice == 3)
            {
                m->editTaskMenu();
            }
            else if (choice == 4)
            {
                m->organizeTasksMenu();
            }
            else if (choice != 5)
            {
                cout << "Invalid Value! Returning to main menu..." << endl;
            }
        }
        else if (choice == 2)
        {
            m->printTaskList();
        }
        else if (choice == 3)
        {
            m->printHelp();
        }
        else if (choice != 0)
        {
            cout << "Invalid Value! Returning to main menu..." << endl;
        }
    }

    return 0;
}