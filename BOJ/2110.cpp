#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    int *house = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> house[i];
    }

    sort(house, house+n);

    int low = 1, high = house[n-1]-house[0];
    int distance = 0, result = 0;
    
    while (low <= high) {
        int mid = (low+high)/2;
        int now = house[0];
        int cnt = 1;

        for (int i = 1; i < n; i++) {
            distance = house[i] - now;

            if (distance >= mid) {
                cnt++;
                now = house[i];
            }
        }
        
        if (cnt >= c) {
            result = mid;
            low = mid + 1;
        } else high = mid - 1;
    }
    cout << result;

    return 0;
}