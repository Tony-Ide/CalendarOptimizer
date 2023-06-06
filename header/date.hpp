#ifndef DATE_HPP
#define DATE_HPP

using namespace std;

#include <string>
class Date{
    private:
    int month;
    int day;

    public:
    Date();
    Date(int, int);

    int getMonth();
    int getDay();

};

#endif // DATE_HPP