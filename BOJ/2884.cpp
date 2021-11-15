#include <iostream>
using namespace std;

int main() {
    int h, m, minutes;
    cin >> h >> m;

    if(h == 0) h = 24;
    minutes = h * 60 + m;
    minutes -= 45;
    h = minutes / 60;
    m = minutes % 60;
    if(h == 24) h = 0;

    cout << h << " " << m;

    return 0;
}