#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    stack<int> st;

    while (n--)
    {
        string s;
        cin >> s;

        if (s == "push")
        {
            int p;
            cin >> p;
            st.push(p);
        }
        else if (s == "pop")
        {
            if (st.empty())
                cout << -1 << '\n';
            else
            {
                cout << st.top() << '\n';
                st.pop();
            }
        }
        else if (s == "size")
        {
            cout << st.size() << '\n';
        }
        else if (s == "empty")
        {
            cout << st.empty() << '\n';
        }
        else if (s == "top")
        {
            if (st.empty())
                cout << -1 << '\n';
            else
                cout << st.top() << '\n';
        }
    }
    return 0;
}