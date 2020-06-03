#include <iostream>
#include <vector>
#include <string>
#include "helloworld.hpp"

using namespace std;

HelloWorld::HelloWorld(bool inputCondition) {
    condition = inputCondition;
    string msg;
}

HelloWorld::~HelloWorld() {
    return;
};

string HelloWorld::get_message() {
    if (condition) {
        msg = "Hello the condition is true.";
    } else {
        msg = "Hello the condition is false.";
    }

    return msg;
}