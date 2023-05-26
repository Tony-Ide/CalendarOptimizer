#ifndef DATE_HPP
#define DATE_HPP

using namespace std;

#include <string>
class Date{
    private:
    string month;
    int day;

    public:
    Date();
    Date(string, int);

    string getMonth();
    int getDay();

};

#endif // DATE_HPP