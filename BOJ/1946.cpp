#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    int c;
    cin >> c;

    while (c--) {   // c가 0이 될 때까지
        int a, result = 1;
        cin >> a;
        pair<int, int> rank[a];

        for (int i = 0; i < a; ++i) {
            cin >> rank[i].first >> rank[i].second;
        }

        sort(rank, rank + a);

        int temp = rank[0].second;
        for (int i = 1; i < a; i++) {
            if (rank[i].second < temp) {
                result++;
                temp = rank[i].second;

                if (temp == 1) {
                    break;
                }
            }
        }
        cout << result << endl;
    }

    return 0;
}