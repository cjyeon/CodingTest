#include <iostream>
#include <queue>
using namespace std;

#define MAX 100001
bool visit[MAX];

int main() {
    int n, k, answer = 0;
    cin >> n >> k;

    queue< pair<int, int> > q;
    q.push(make_pair(n, 0));
    visit[n] = true;

    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        if (a == k) {
            answer = b;
            break;
        }

        if (a - 1 >= 0 && !visit[a-1])
        {
            q.push(make_pair(a - 1, b+1));
            visit[a-1] = true;
        }
        if (a + 1 < MAX && !visit[a+1])
        {
            q.push(make_pair(a + 1, b+1));
            visit[a+1] = true;
        }
        if (a * 2 < MAX && !visit[a*2])
        {
            q.push(make_pair(a * 2, b+1));
            visit[a*2] = true;
        }
    }

    cout << answer << endl;
    return 0;
}