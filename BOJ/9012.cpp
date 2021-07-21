#include <iostream>
#include <stack>
using namespace std;

bool bracket(string s)
{
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            if (!st.empty())
                st.pop();
            else
                return false;
        }
    }

    return st.empty();
}

int main()
{
    int k;
    string s;

    cin >> k;

    while (k--)
    {
        cin >> s;

        if (bracket(s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}