#include <iostream>
#include "../header/main_menu.hpp"
#include "../header/scheduler.hpp"
using namespace std;

int main()
{
    Scheduler* hi = new Scheduler();
    MainMenu* m = new MainMenu(hi);
    m->editTaskMenu();

    return 0;
}