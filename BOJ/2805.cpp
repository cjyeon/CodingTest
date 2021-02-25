#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
long m;
long long arr[1000000];

bool solution(long long h) {
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - h > 0)
            sum += arr[i] - h;
    }
    if (sum >= m) return true;
    return false;
}

int main() {
    long long low = 1, high = 0;
    long long ans = 0;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        high = max(high, arr[i]);
    }

    while(low <= high){
        long long mid = (low+high)/2;
        if (solution(mid)) {
            ans = max(ans, mid);
            low = mid + 1;
        }
        else high = mid -1;
    }
    cout << ans << endl;

    return 0;
}