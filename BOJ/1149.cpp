#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, cost[3];
    int house[1001][3];
    cin >> n;

    house[0][0] = 0;
    house[0][1] = 0;
    house[0][2] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> cost[0] >> cost[1] >> cost[2];
        house[i][0] = min(house[i-1][1], house[i-1][2]) + cost[0];
        house[i][1] = min(house[i-1][0], house[i-1][2]) + cost[1];
        house[i][2] = min(house[i-1][0], house[i-1][1]) + cost[2];
    }
    cout << min(house[n][0], min(house[n][1], house[n][2])) << endl;
    
    return 0;
}