#include <iostream>
#include <vector>
#include <string>
using namespace std;

class HelloWorld {
    private:
        bool condition;
        string msg;
    public:
        HelloWorld(bool inputCondition);
        ~HelloWorld();
        string get_message();
};