#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    bool condition;
    vector<string> msg;

    condition = true;

    if (condition) {
        msg.assign({"Hello", "the", "condition", "is", "true."});
    } else {
        msg.assign({"Hello", "the", "condition", "is", "false."});
    }
    
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}