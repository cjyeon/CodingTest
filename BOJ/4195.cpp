#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, string> parent;
unordered_map<string, int> cnt;

//최상위 부모 index 리턴
string find(string s)
{
    if (parent[s] == s) return s;
    else return parent[s] = find(parent[s]);
}

void uni(string a, string b)
{
    string A = find(a);
    string B = find(b);
    if (A == B) return;

    //둘이 부모 다르면 한쪽으로 이동
    parent[B] = A;
    cnt[A] += cnt[B];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int inputcase, n;
    cin >> inputcase;

    while (inputcase--)
    {
        cin >> n;
        
        parent.clear();
        cnt.clear();

        while (n--)
        {
            string a, b;
            cin >> a >> b;
            if (parent.count(a) == 0)
            {
                parent.insert(make_pair(a, a));
                cnt.insert(make_pair(a, 1));
            }
            if (cnt.count(b) == 0)
            {
                parent.insert(make_pair(b, b));
                cnt.insert(make_pair(b, 1));
            }
            uni(a, b);
            cout << cnt[find(a)] << '\n';
        }
    }

    return 0;
}