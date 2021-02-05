#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, count_L = 0, result = 0;
    string s;
    cin >> n >> s;

    if (n == 1) {
        result++;
    }
    else {
        for (int i = 0; i < n; i++) {
            if (toupper(s[i]) == 'L') {
                if (count_L % 2 == 1) {
                    count_L++;
                    continue;
                } else {
                    count_L++;
                    result++;
                }
            } else if (toupper(s[i]) == 'S') {
                result++;
            }
        }
    }

    cout << min(n, ++result);

    return 0;
}