#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap; // top() = min

    while (n--)
    {
        int num;
        cin >> num;

        if (maxheap.empty())
            maxheap.push(num);
        else
        {
            if (minheap.size() < maxheap.size())
                minheap.push(num);

            else
                maxheap.push(num);

            if (maxheap.top() > minheap.top())
            {
                int max = maxheap.top();
                int min = minheap.top();
                maxheap.pop();
                minheap.pop();
                maxheap.push(min);
                minheap.push(max);
            }
        }

        cout << maxheap.top() << '\n';
    }

    return 0;
}