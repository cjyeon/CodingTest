#include <iostream>
using namespace std;

int main() {
    int n, now = 666;
    string result;
    cin >> n;

    while (n >= 0) {
        result = to_string(now);
        for (int i = 0; i < result.length() - 2; i++) {
            if (result[i] == '6' && result[i+1] == '6' && result[i+2] == '6') {
                n--;
                if (n == 0) {
                    cout << now;
                    return 0;
                }
                break;
            }
        }
        now++;
    }

    return 0;
}