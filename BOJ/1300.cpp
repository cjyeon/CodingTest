#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int left = 1, right = m, result;
    while (left <= right) {
        unsigned int cnt = 0;
        int mid = (left + right) / 2;

        for (int i = 1; i <= n; i++) {
            cnt += min(mid / i, n);
        }
        if(cnt < m) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
            result = mid;
        }
    }
    cout << result << '\n';

    return 0;
}