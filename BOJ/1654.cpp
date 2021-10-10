#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    long long n, m, max = 0, result = 0;
    cin >> n >> m;

    long long lan[n];
    for (int i = 0; i < n; i++) {
        cin >> lan[i];
        if(lan[i] > max) max = lan[i];
    }

    long long range_begin = 1, range_end = max, mid;

    while (range_begin <= range_end)
    {
        mid = (range_begin + range_end) / 2;
        long long answer = 0;

        for (auto i : lan) {
            answer += i / mid;
        }

        if (answer >= m) {
            range_begin = mid + 1;
            if(mid > result) result = mid;
        }
        else 
            range_end = mid-1;
    }

    cout << result << '\n';    

    return 0;
}