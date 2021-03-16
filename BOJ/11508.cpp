#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long sum = 0;
    long long price[100001];
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> price[i];
    sort(price, price+n, greater<int>());

    for (int i = 0; i < n; i++) {
        if (i % 3 != 2) 
            sum += price[i];
    }
    cout << sum ;

    return 0;
}