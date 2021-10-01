#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    int n;
    cin >> s >> n;

    stack<char> st_edit1, st_edit2;
    for (auto &c:s)
    {
        st_edit1.push(c);
    }

    while(n--) {
        char command;
        cin >> command;

        if (command == 'L' && !st_edit1.empty()) {
            st_edit2.push(st_edit1.top());
            st_edit1.pop();
        }

        else if (command == 'D' && !st_edit2.empty()) {
            st_edit1.push(st_edit2.top());
            st_edit2.pop();
        }

        else if (command == 'B' && !st_edit1.empty()) 
            st_edit1.pop();

        else if (command == 'P') {
            char plus;
            cin >> plus;
            st_edit1.push(plus);
        }
    }

    while(!st_edit1.empty()) {
        st_edit2.push(st_edit1.top());
        st_edit1.pop();
    }

    while(!st_edit2.empty()) {
        cout << st_edit2.top();
        st_edit2.pop();
    }

    return 0;
}