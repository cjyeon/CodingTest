#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int,int> P;

bool compare(P a, P b) {
    if(a.second == b.second){
        return a.first < b.first;
    }
    else{
        return a.second < b.second;
    }
}

int main() {
    int n, temp, result = 1;
    cin >> n;
    vector<P> v;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(), v.end(), compare);

    temp = v[0].second;
    for (int i = 1; i < n; i++)
    {
        if (temp <= v[i].first) 
        {
            temp = v[i].second;
            result++;
        }
    }
    cout << result << endl;

    return 0;
}