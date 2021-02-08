#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long n, c, result = 0;
    cin >> n >> c;
    long long arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < c; i++) {[]
        sort(arr, arr+n);
        long long temp = arr[0] + arr[1];
        arr[0] = temp;
        arr[1] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        result += arr[i];
    }
    cout << result << endl;

    return 0;
}