#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long 
    int n, k, result = 0;
    cin >> n >> k;
    int arr[n], sum[n-1];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        sum[i] = abs(arr[i] - arr[i + 1]);
    }
    sort(sum, sum+n-1);

    for (int i = 0; i < n-1-(k-1); i++)
    {
        result += sum[i];
    }

    cout << result << endl;

    return 0;
}