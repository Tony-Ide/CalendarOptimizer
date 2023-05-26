
#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
using namespace std;

class userinterface{
    private:
    vector<string> userInput;
    
    public:
    enum class command: uint8_t {
      add,
      edit,
      remove,    
      help,
      error
    };
    void getLineFromUser();
    userinterface();
    userinterface(string input);
    userinterface::command judgeInput();
    vector<string> getUserInput();
};

#endif // USERINPUT_HPP