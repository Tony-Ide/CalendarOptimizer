#include "../header/todo.hpp"
using namespace std;
Todo::Todo(Date* d, string n, int p, int t, int dur){
    date = d;
    name = n;
    time = t;
    durationTime = dur;
}

string Todo::getName(){
    return name;
}

