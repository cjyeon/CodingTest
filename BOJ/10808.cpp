#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, int> umap;
    string s;
    cin >> s;

    for (int i = 0; i < 26; i++)
    {
        umap[i] = 0;
    }

    for (int i = 0; i < s.size(); i++) {
        umap[s[i]-97]++;
    }
    
    for (int i = 0; i < 26; i++)
    {
        cout << umap[i] << " ";
    }

    return 0;
}