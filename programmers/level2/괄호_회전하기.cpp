#include <string>
#include <queue>
#include <stack>

using namespace std;

stack<char> st;

void check(char c) {
    if (c == '(' || c == '{' || c == '[') st.push(c);
    else if (!st.empty()) {
        if(c == ')' && st.top() == '(') st.pop();
        else if(c == '}' && st.top() == '{') st.pop();
        else if(c == ']' && st.top() == '[') st.pop();
    }
    else st.push(c);
}

int solution(string s) {
    int answer = 0;
    queue<char> q;
    
    for(int i = 0; i < s.size(); i++) {
        q.push(s[i]);
    }
    
    for(int i = 0; i < s.size(); i++) {
        if(i > 0) {
            q.push(q.front());
            q.pop();
        }
        
        for(int j = 0; j < q.size(); j++) {
            check(q.front());
            q.push(q.front());
            q.pop();
        }
        if(st.empty()) answer++;
        
        while(!st.empty()) st.pop();
    }
    
    return answer;
}