#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<char, bool>> ant;
    int a, b, c;
    cin >> a >> b;

    for (int i = 0; i < a; i++) {
        char c;
        cin >> c;
        ant.push_back({c, 0});
    }
    reverse(ant.begin(), ant.end());
    for (int i = 0; i < b; i++) {
        char c;
        cin >> c;
        ant.push_back({c, 1});
    }

    cin >> c;
    while(c--) {
        for (int i = 0; i < ant.size(); i++) {
            pair<char, bool> tmp;
            if(!ant[i].second && ant[i+1].second) {
                tmp = ant[i];
                ant[i] = ant[i+1];
                ant[i+1] = tmp;
                i++;
            }
            else continue;
        }
    }

    for (int i = 0; i < ant.size(); i++) 
        cout << ant[i].first;

    return 0;
}