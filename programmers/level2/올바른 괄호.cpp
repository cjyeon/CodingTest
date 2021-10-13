#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<int> st;

    for(char c : s) {
        if(c == '(') st.push(c);
        else {
            if(!st.empty()) st.pop();
            else return false;
        }
    }

    if(!st.empty()) answer = false;
    return answer;
}