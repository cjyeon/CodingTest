#include <iostream>
using namespace std;

int main() {
    int n, sum, tmp;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        sum = i;
        tmp = i;

        while(tmp) {
            sum += tmp%10;
            tmp /= 10;
        }

        if (n == sum)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << "0" << endl;

    return 0;
}

