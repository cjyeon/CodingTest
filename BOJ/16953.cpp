#include <iostream>
using namespace std;

int main() {
    int a, b, result = 0;
    
    cin >> a >> b;

    while(true) {
        if(b == a) {
            cout << ++result << endl;
            break;
        } 
        if (a > b) {
            cout << -1 << endl;
            break;
        } else if (b % 10 == 1) {
            b /= 10;
        } else if (b % 2 == 0) {
            b /= 2 ;
        } else {
            cout << -1 << endl;
            break;
        }
        result++;
    }
    return 0;   
}