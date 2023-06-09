#include "../header/UserInterface.hpp"

std::vector<std::string> splitString(std::string str, char Delimiter) {
    std::istringstream iss(str);             
    std::string buffer;                      
    std::vector<std::string> result;
    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);              
    }
    return result;
}
bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void UserInterface::getLineFromUser(){
    std::string userinput;
    getline(std::cin,userinput);
    this->userInput = splitString(userinput,' ');
}
UserInterface::UserInterface(){

}
UserInterface::UserInterface(std::string input){
    this->userInput = splitString(input,' ');
    checkInvalidValue();
}
std::vector<std::string> UserInterface::getUserInput(){
    return userInput;
}
void UserInterface::checkInvalidValue(){
    bool commandExists = false;
    for(int i=0;i<this->commands.size();i++){
        if(userInput[0].compare(commands[i])){    
            commandExists = true;
        }
        
    }
    if(commandExists == false){
        throw std::string("invalid command");
    }

    if(userInput.size() > 2){
        std::vector<std::string> date = splitString(userInput[2],'/');
        if(!is_number(date[0]) || date[0].size() != 2 || std::stoi(date[0])<1 || std::stoi(date[0])>12){
            throw std::string("invalid month");
         }
        if(!is_number(date[1]) || date[1].size() != 2 || std::stoi(date[1])<1 || std::stoi(date[1])>31){
            throw std::string("invalid day");
        }
        if(!is_number(userInput[3]) || std::stoi(userInput[3])<0){
            throw std::string("invalid duration time");
        }
        if(!is_number(userInput[4]) || std::stoi(userInput[4])<0 || std::stoi(userInput[4])>3){
            throw std::string("invalid proity");
        }
    }
}
void UserInterface::judgeInput(){
    if(this->userInput[0] == "add"){

    }
    else if(this->userInput[0] == "edit"){
        
    }
    else if(this->userInput[0] == "remove"){
 
    }
    else if(this->userInput[0] == "help"){

    }
    else if(this->userInput[0] == "optimize"){

    }
    else{

    }
    
}