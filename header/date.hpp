#ifndef DATE_HPP
#define DATE_HPP

using namespace std;

#include <string>
class Date{
    private:

    public:
    Date();
    Date(string, int);
    string month;
    int day;

    string getMonth();
    int getDay();

};

#endif // DATE_HPP