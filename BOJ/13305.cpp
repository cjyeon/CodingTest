#include <iostream>
using namespace std;

long long distc[100000-1];
long long price[10000];
long long min_cost = 10000000000;
long long cost = 0;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n-1; i++) {
        cin >> distc[i];
    }
    for (int i = 0; i < n-1; i++) {
        cin >> price[i];
        if (min_cost > price[i]) min_cost = price[i];
        cost += min_cost * distc[i];
    }
    cout << cost << endl;

    return 0;
}