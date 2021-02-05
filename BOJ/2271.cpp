#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, result = 0;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        result = max(result, arr[i] * (n - i));
    }

    cout << result;

    return 0;
}
