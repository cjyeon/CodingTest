#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int a, b, result = 0;
    
    cin >> a >> b;

    for (int i = b; i >= a; i++) {
        if(b == a) {
            cout << ++result;
            break;
        } else if (a > b) {
            cout << -1;
            break;
        } else if (b % 10 == 1) {
            b /= 10;
            result++;
        } else if (b % 2 == 0) {
            b /= 2 ;
            result++;
        }
    }
    
    return 0;   
}