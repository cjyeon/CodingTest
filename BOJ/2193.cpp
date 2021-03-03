#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long prinary[90];

    prinary[0] = 2;
    prinary[1] = 3;
    
    if (n <= 2) {
        cout << 1 << '\n';
        return 0;
    } else if (n <= 4) {
        cout << prinary[n-3] << '\n';
        return 0;
    } else {
        for (int i = 2; i < n-2; i++)
            prinary[i] = prinary[i-1] + prinary[i-2];
    }
    cout << prinary[n-3] << '\n';

    return 0;
}