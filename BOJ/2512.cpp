#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, max;
    cin >> n;
    int budget[n];

    for (int i = 0; i < n; i++)
    {
        cin >> budget[i];
    }
    cin >> max;
    sort(budget, budget + n);

    int left = 0, right = budget[n - 1];
    int result, sum;
    while (left <= right)
    {
        sum = 0;
        int mid = (left + right) / 2;
        for (int i = 0; i < n; i++)
        {
            sum += min(budget[i], mid);
        }
        if (max >= sum)
        {
            result = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << result << '\n';
    return 0;
}