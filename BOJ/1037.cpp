#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, result;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    if (n == 1)
    {
        result = arr[0]*arr[0];
    } 
    else {
        result = arr[0]*arr[n-1];
    }
    
    cout << result;
}