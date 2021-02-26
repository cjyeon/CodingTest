#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<long long> vec;

int solution(int a, int b, int target) {
    int mid = (a+b)/2;
    if(a > b ) return 0;
    else {
        if (target == vec[mid]) return 1;
        else if (target > vec[mid]) 
            return solution(mid+1, b, target);
        else 
            return solution(a, mid-1, target);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long tmp; 
        cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    int mid = vec[n/2];

    cin >> m;
    for (int i = 0; i < m; i++) {
        long long tmp;
        cin >> tmp;
        cout << solution(0, n-1, tmp) << " ";
    }
    return 0;
}