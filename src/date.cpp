#include "../header/date.hpp"
using namespace std;

Date::Date(){
    month=0;
    day=0;
}
Date::Date(int m, int d){
    month=m;
    day=d;
}

int Date::getMonth(){
    return month;
}
    
    
int Date::getDay(){
    return day;
}