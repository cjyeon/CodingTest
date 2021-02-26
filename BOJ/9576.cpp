#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int c;
    cin >> c;
    
    while(c--)
    {
        int n, m;
        cin >> n >> m;
        pair<int, int> book[1000];
        bool visited[1001] = {0,};

        for (int i = 0; i < m; i++)
            cin >> book[i].second >> book[i].first;     // 두번째 입력값으로 정렬
        sort(book, book+m);

        for (int i = 0; i < m; i++) {
            for (int j = book[i].second; j <= book[i].first; j++) {
                if (!visited[j]) {
                    visited[j] = 1;
                    break;
                }
            }
        }
        int result = 0;
        for (int i = 1; i <= n; i++)
            if (visited[i]) result++; 
        cout << result << "\n";
    }
    return 0;
}