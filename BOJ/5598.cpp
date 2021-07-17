#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    
    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] < 68)
        {
            str[i] += 23 ;
        }
        else str[i] -= 3;

        cout << str[i];
    }
    return 0;
}