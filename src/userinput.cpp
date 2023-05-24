#include "../header/userinterface.hpp"

vector<string> split(string str, char Delimiter) {
    istringstream iss(str);             
    string buffer;                      
    vector<string> result;
    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);              
    }
    return result;
}

userinterface::userinterface(string input){
    this->userInput = split(input,' ');
}

userinterface::command userinterface::judgeInput(){
    if(this->userInput[0] == "add"){
        return userinterface::command::add;
    }
    else if(this->userInput[0] == "edit"){
        return userinterface::command::edit;
    }
    else if(this->userInput[0] == "remove"){
        return userinterface::command::remove;
    }
    else if(this->userInput[0] == "help"){
        return userinterface::command::help;
    }
    else{
        return userinterface::command::error;
    }
    
}