#include <iostream>
using namespace std;

int main() {
    int num[9];
    int max = 0, n;

    for (int i = 0; i < 9; i++)
    {
        cin >> num[i];

        if (num[i] >= max)
        {
            max = num[i];
            n = i;
        }
    }
    
    cout << max << endl << n+1;
}