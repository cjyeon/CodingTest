#include <iostream>
#include <vector>
using namespace std;

int n, result = 0;
vector < pair<int,int> > vec;

void solution(int num, int sum) {
    if(num > n) return;
    result = max(result, sum);
    for (int i = num; i < n; i++) {
        solution(i + vec[i].first, sum + vec[i].second);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vec.push_back(make_pair(a, b));
    }
    
    for (int i = 0; i < n; i++) {
        solution(i + vec[i].first, vec[i].second);
    }
    cout << result << endl;

    return 0;
}