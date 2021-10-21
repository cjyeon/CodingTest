#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    int arr[3] = {300, 60, 10};
    int result[3] = {0, 0, 0};

    while (t >= arr[2]) {
        for (int i = 0; i < 3; i++) {
            while(t >= arr[i]) {
                t -= arr[i];
                result[i]++;
            }
        }
    }

    if (t != 0)
        cout << -1;
    else 
        for(int i : result) cout << i << " " ;

    return 0;
}