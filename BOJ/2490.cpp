#include <iostream>
using namespace std;

int main() {
    for(int i = 0; i < 3; i++) {
        int a = 0;

        for(int i = 0; i < 4; i++) {
            int num;
            cin >> num;
            if(!num) a++;
        }

        switch (a) {
        case 1:
            cout << "A" << '\n';
            break;
        
        case 2:
            cout << "B" << '\n';
            break;

        case 3:
            cout << "C" << '\n';
            break;

        case 4:
            cout << "D" << '\n';
            break;

        default:
            cout << "E" << '\n';
        }
    }

    return 0;
}