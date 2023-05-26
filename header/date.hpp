#ifndef DATE_HPP
#define DATE_HPP
using namespace std;
#include <string>
class Date{
    private:


    public:
    Date(string, int);
    string getMonth();
    int getDay();

    string month;
    int day;


};

#endif // DATE_HPP