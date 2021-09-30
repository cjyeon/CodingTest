#include <iostream>
#include <queue>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    priority_queue<int> pq;
    cin >> n;

    while (n--)
    {
        int a;
        cin >> a;
        if(a == 0) {
            if (pq.empty())
                cout << 0;
            else {
                cout << pq.top();
                pq.pop();
            }
            cout << '\n';
        }
        else pq.push(a);
    }

    return 0;
}