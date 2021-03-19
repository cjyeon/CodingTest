#include <iostream>
using namespace std;

void star(int a, int b, int n) {
    if ((a/n) % 3 == 1 && (b/n) % 3 == 1)
        cout << ' ';
    else {
        if (n / 3 == 0)
            cout << '*';
        else
            star(a, b, n/3);
    }
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            star(i, j, n);
        }
        cout << endl;
    }
    
    return 0;
}