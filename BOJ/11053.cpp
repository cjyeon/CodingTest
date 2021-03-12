#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, result = 0;
    int arr[1000];
    int dp[1000];
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    for (int i = 0; i < n; i++) {
        dp[i] = 1;

        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) 
                dp[i] = max(dp[i], dp[j]+1);
        }
        result = max(result, dp[i]);
        
    }
    cout << result;

    return 0;
}