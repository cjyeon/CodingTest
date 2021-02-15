#include <iostream>
#include <queue>
using namespace std;

bool line[101][101] = {0,};
bool visited_node[101] = {0,};
int result = 0;

void bfs(int n, int l) {
    queue<int> q;

    visited_node[l] = 1;
    q.push(l);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if(line[now][i] && !visited_node[i]) {
                q.push(i);
                visited_node[i] = 1;
                int now = q.front();
                result++;
            }
        }        
    }
    cout << result << endl;
}

int main() {
    int n, l;
    cin >> n >> l;

    while (l--) {
        int x, y;
        cin >> x >> y;
        line[x][y] = 1;
        line[y][x] = 1;
    }
    
    bfs(n, 1);
    return 0;
}