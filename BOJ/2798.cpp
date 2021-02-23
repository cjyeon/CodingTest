#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[101];
vector<int> result;

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < n-2; i++) {
        for (int j = i+1; j < n-1; j++) {
            for (int k = j+1; k < n; k++) {
                if(arr[i] + arr[j] + arr[k] <= m)
                    result.push_back(arr[i] + arr[j] + arr[k]);
            }
        }
    }
    sort(result.begin(), result.end());

    cout << result.back() << endl;

    return 0;
}