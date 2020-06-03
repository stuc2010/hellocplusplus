#include "lib/HelloWorld/helloworld.hpp"

using namespace std;

int main()
{
    HelloWorld hello(false);
    string msg = hello.get_message();

    cout << msg <<endl;
}