#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> P;
P a[300001];
int b[300001];
priority_queue<int> pq;

int main()
{
    int n, k;
    long long result = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    for (int i = 0; i < k; i++)
    {
        cin >> b[i];
    }
    sort(a, a+n);
    sort(b, b+k);

    int j = 0;
	for(int i = 0; i < k; i++) {
		while(j < n && a[j].first <= b[i])
			pq.push(a[j++].second);		
		if(!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}

    cout << result << endl;

    return 0;
}