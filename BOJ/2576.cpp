#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec;
    int sum = 0, max;

    for (int i = 0; i < 7; i++)
    {
        int num;
        cin >> num;

        if (num % 2 == 1)
        {
            vec.push_back(num);
            sum += num;
        }
    }

    if (vec.empty())
    {
        cout << -1;
        return 0;
    }

    sort(vec.begin(), vec.end());

    cout << sum << endl << vec.at(0);    
}