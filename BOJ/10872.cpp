#include <iostream>
using namespace std;

int main() {
    int n, result = 1;
    cin >> n;

    if(n < 1) {

        cout << 1;
        return 0;
    }
    else {
        for (int i = n; i > 0; i--)
        {
            result *= i;
        }
    }
    cout << result;

}