#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int num;
    cin >> num;
    vector<pair<int, int>> lec;
    priority_queue<int, vector<int>, greater<int>> result;

    for(int i = 0; i < num; i++) {
        int a, b;
        cin >> a >> b;
        lec.push_back({a, b});
    }
    sort(lec.begin(), lec.end());

    result.push(lec[0].second);

    for (int i = 1; i < num; i++) {
         if (result.top() <= lec[i].first) {
            result.pop();
            result.push(lec[i].second);
        }
        else {
            result.push(lec[i].second);           
        }
    }
    
    cout << result.size();

    return 0;
}