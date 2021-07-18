#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k, n;
    cin >> k;

    while(k--) {
        vector<int> vec;
        cin >> n;

        for (int i = n; i > 0; i /= 2)
        {
            vec.push_back(i % 2);
        }

        for (int i = 0; i < vec.size(); i++)
        {
            if (vec.at(i) == 1) cout << i << " ";
        }
        cout << endl;
    }
}