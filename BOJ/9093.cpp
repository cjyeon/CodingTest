#include <iostream>
#include <stack>
using namespace std;

int main() {
    int k;
    string s;
    stack<char> st;

    cin >> k;
    cin.ignore();   //버퍼 비우기

    while(k--) {
        getline(cin, s);
        s += ' ';
        
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ') {
                while(!st.empty()) {
                    cout << st.top();
                    st.pop();
                }
                cout << ' ' ;
            }
            else 
                st.push(s[i]);
        }

        cout << endl;
    }
}