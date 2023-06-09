
#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class UserInterface{
    private:
    std::vector<std::string> userInput;
    //Todo todo;
    std::vector<std::string> commands={"add","edit","remove","organize","help"};
    std::vector<std::string> screens={"weekview","monthview","dayview"}

    public:
    void getLineFromUser();
    UserInterface();
    UserInterface(std::string input);
    void judgeInput();
    std::vector<std::string> getUserInput();
    void checkInvalidValue();
};

#endif // USERINPUT_HPP