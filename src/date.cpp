#include "../header/date.hpp"
using namespace std;

Date::Date(string m, int d){
    month=m;
    day=d;
}

string Date::getMonth()
{
    return month;
}

int Date::getDay()
{
    return day;
}