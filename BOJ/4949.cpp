#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
    {
        string s;
        getline(cin, s);
        stack<char> st;
        bool check = true;

        if (s.length() == 1 && s[0] == '.') break;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[')
            {
                st.push(s[i]);
            }
            if (s[i] == ')')
            {
                if (st.empty() || st.top() == '[')
                    check = false;
                else
                    st.pop();
            }
            if (s[i] == ']')
            {
                if (st.empty() || st.top() == '(')
                    check = false;
                else
                    st.pop();
            }
        }
        if (st.empty() && check)
            cout << "yes" << '\n'; 
        else
            cout << "no" << '\n';
    }
    return 0;
}