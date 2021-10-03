#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    while (n--)
    {
        string s;
        cin >> s;

        stack<char> st_edit1, st_edit2;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '<')
            {
                if (!st_edit2.empty())
                {
                    st_edit1.push(st_edit2.top());
                    st_edit2.pop();
                }
            }

            else if (s[i] == '>')
            {
                if (!st_edit1.empty())
                {
                    st_edit2.push(st_edit1.top());
                    st_edit1.pop();
                }
            }

            else if (s[i] == '-')
            {
                if (!st_edit2.empty())
                    st_edit2.pop();
            }

            else
            {
                st_edit2.push(s[i]);
            }
        }

        while (!st_edit1.empty())
        {
            st_edit2.push(st_edit1.top());
            st_edit1.pop();
        }

        string answer;
        while (!st_edit2.empty())
        {
            answer += st_edit2.top();
            st_edit2.pop();
        }

        reverse(answer.begin(), answer.end());
        cout << answer << '\n';
    }

    return 0;
}