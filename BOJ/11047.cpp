#include <iostream>
using namespace std;

int main()
{
    int n, sum, result = 0;
    cin >> n >> sum;
    int arr[n], j = n - 1;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = n - 1; sum > 0;) {
        if (sum >= arr[j]) {
            result += sum / arr[j];
            sum %= arr[j];
        } else j--;
    }

    cout << result;

    return 0;
}
