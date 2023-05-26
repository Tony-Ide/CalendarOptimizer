#include "../header/date.hpp"


Date::Date(string m, int d){
    month = m;
    day = d;

using namespace std;
Date::Date(string m, int d){
    month=m;
    day=d;
}

string Date::getMonth(){
    return month;
}
    
    
int Date::getDay(){
    return day;

}