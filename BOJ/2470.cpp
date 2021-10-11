#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);

    int left = 0, right = n-1, a = arr[left], b = arr[right], sum = a + b; 
    while (left < right) {
        int tmp = arr[left] + arr[right];
        if (abs(tmp) < abs(sum)) {
            sum = arr[left] + arr[right];
            a = arr[left];
            b = arr[right];
        }
        if (tmp <= 0) left++;
        else right--;
    }

    cout << a << " " << b << '\n';
    
    return 0;
}