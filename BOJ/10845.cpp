#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<int> qu;

    while (n--)
    {
        string s;
        cin >> s;

        if (s == "push")
        {
            int p;
            cin >> p;
            qu.push(p);
        }
        else if (s == "pop")
        {
            if (qu.empty())
                cout << -1 << '\n';
            else
            {
                cout << qu.front() << '\n';
                qu.pop();
            }
        }
        else if (s == "size")
        {
            cout << qu.size() << '\n';
        }
        else if (s == "empty")
        {
            cout << qu.empty() << '\n';
        }
        else if (s == "front")
        {
            if (qu.empty())
                cout << -1 << '\n';
            else
                cout << qu.front() << '\n';
        } 
        else if (s == "back")
        {
            if (qu.empty())
                cout << -1 << '\n';
            else
                cout << qu.back() << '\n';
        }
    }
    return 0;
}