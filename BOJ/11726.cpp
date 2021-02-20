#include <iostream>
using namespace std;

int main() {
    int n; 
    int square[1000];
    cin >> n;

    square[0] = 1;
    square[1] = 1;

    for (int i = 2; i <= n; i++) {
        square[i] = (square[i-1] + square[i-2]) % 10007;
    }
    
    cout << square[n];

    return 0;
}