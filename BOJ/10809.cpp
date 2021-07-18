#include <iostream>
using namespace std;

int main() {
    string s;
    int alphabet[26];
    fill_n(alphabet, 26, -1);
    cin >> s;
    
    for (int i = 0; i < s.size(); i++)
    {
        int index = s[i] - 97;
        if(alphabet[index] == -1)  alphabet[index] = i;
        else continue;
    }

    for (int i = 0; i < 26; i++)
    {
        cout << alphabet[i] << " ";
    }

}