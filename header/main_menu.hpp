#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP
#include "scheduler.hpp"
class MainMenu{
    private:
    Scheduler* scheduler; // Pointer to Schedule object



    public:
    MainMenu(Scheduler* schedule);
    void printTaskList(); 
    void printWeek(Date* targetDate);
    void printDay(Date* targetDate);

    void printHelp();

    void printTaskTable();
    void  editTaskMenu();
    void  addTaskMenu();
    void deleteTaskMenu();
    void organizeTasksMenu();
};

#endif // MAIN_MENU_HPP