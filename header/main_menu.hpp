#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP
#include "scheduler.hpp"
class MainMenu{
    private:
    Scheduler* scheduler; // Pointer to Schedule object



    public:
    MainMenu(Scheduler*);
    void printCalendar(); 

    void printHelp();

    void printTaskTable();
    void  editTaskMenu();


};

#endif // MAIN_MENU_HPP