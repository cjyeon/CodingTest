#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, best = 0;
    cin >> n;
    map<string, int> books;

    while (n--)
    {
        string s;
        cin >> s;
        books[s]++;
    }

    for (auto i = books.begin(); i != books.end(); i++)
    {
        best = max(best, i -> second);
    }

    for (auto j = books.begin(); j != books.end(); j++)
    {
        if (best == j -> second) {
            cout << j -> first;
            return 0;
        }
    }

    return 0;
}