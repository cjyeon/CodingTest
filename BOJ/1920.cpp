#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 100000;

int n, m;
vector<int> vec;

int binary(int a, int b, int target) {
    if (a > b)
        return 0;
    else {
        int m = (a+b)/2;
        if (vec[m] == target)
            return 1;
        else if (vec[m] > target)
            return binary(a, m-1, target);
        else 
            return binary(m+1, b, target);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(), vec.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        cout << binary(0, n-1, a) << '\n';
    }

    return 0;
}