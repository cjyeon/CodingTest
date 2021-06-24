#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int k, n, m;
    int answer;

    cin >> k;
    while (k--)
    {
        answer = 0;
        queue<pair<int, int>> q;
        priority_queue<int> pq;

        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            q.push({i, num});
            pq.push(num);
        }

        while (!q.empty())
        {
            int index = q.front().first;
            int value = q.front().second;
            q.pop();

            if(pq.top() == value) {
                answer++;
                pq.pop();
                if (index == m)
                {
                    cout << answer << endl;
                    break;
                }
            } else q.push({index, value}); 
        }
    }
    return 0;
}