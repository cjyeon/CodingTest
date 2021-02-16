#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, i;
    int dp[1000001];
    int a,b,c;
    cin >> n;

    for (i = 2; i <= n; i++) {   
        a = b = c = 99999;
        if (i%2 == 0) a = dp[i/2]+1;
        if (i%3 == 0) b = dp[i/3]+1;
        c = dp[i-1]+1;

        dp[i] = min({a, b, c});
    }
    cout << dp[n] << endl;
    
    return 0;
}