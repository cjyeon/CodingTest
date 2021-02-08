#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, L;
    cin >> n >> L;
    int fruit[n];

    for (int i = 0; i < n; i++)
    {
        cin >> fruit[i];
    }
    sort(fruit, fruit+n);

    for (int i = 0; i < n; i++)
    {
        if (L >= fruit[i])
        {
            L++;
        }
        else break;
    }
    cout << L << endl;
    
    return 0;
}