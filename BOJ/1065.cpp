#include <iostream>
using namespace std;

int main() {
    int n; 
    cin >> n;

    int result = 99;
    if (n < 100) cout << n;
    else {
        for (int i = 100; i <= n; i++)
        {
            if( i/100 - (i%100)/10 == (i%100)/10 - i%10) result++;
        }
        cout << result;
    }

    return 0;
}