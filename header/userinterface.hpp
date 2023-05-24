
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
    userinterface(string input);
    userinterface::command judgeInput();
};

#endif // USERINPUT_HPP