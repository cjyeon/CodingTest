#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[10001];
    int dp[10001];

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    for (int i = 0; i < 2; i++) {
        if (i == 0)
            dp[i] = arr[i];
        else 
            dp[i] = arr[i] + arr[i-1];
    }
    
    for (int i = 2; i < n; i++) {
        dp[i] = max(arr[i] + arr[i-1] + dp[i-3], arr[i] + dp[i-2]);
        dp[i] = max(dp[i], dp[i-1]);
    }
    cout << dp[n-1] << '\n';

    return 0;
}