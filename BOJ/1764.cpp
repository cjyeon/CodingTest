#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;

    vector<string> vec1, vec2;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        vec1.push_back(s);
    }
    sort(vec1.begin(), vec1.end());
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        if (binary_search(vec1.begin(), vec1.end(), s))
        {
            vec2.push_back(s);
        }
    }
    sort(vec2.begin(), vec2.end());

    cout << vec2.size() << '\n';
    for (string s : vec2)
    {
        cout << s << '\n';
    }

    return 0;
}
