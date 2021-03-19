#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    vector<int> card;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        card.push_back(a);
    }
    sort(card.begin(), card.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        
        cout << upper_bound(card.begin(), card.end(), b) - lower_bound(card.begin(), card.end(), b) << " ";
    }

    return 0;
}