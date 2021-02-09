#include <iostream>
#include <queue>
using namespace std;

bool line[1001][1001] = {0,};
bool dfs_visited[1001] = {0,};
bool bfs_visited[1001] = {0,};

void dfs(int n, int v) {
    dfs_visited[v] = 1;
    cout << v << " ";

    for (int i = 1; i <= n; i++)
    {
        if (line[v][i] && !dfs_visited[i])
        {
            dfs(n, i);
        }
    }
}

void bfs(int n, int v) {
    queue<int> q;

    bfs_visited[v] = 1;
    q.push(v);
    while (!q.empty()) 
    {
        int now = q.front();
        cout << now << " ";
        q.pop();
        for (int i = 1; i <= n; i++)
        {
            if (line[now][i] && !bfs_visited[i])
            {
                q.push(i);
                bfs_visited[i] = 1;
            }   
        } 
    }    
}

int main() {
    int n, m, v;
    cin >> n >> m >> v;

    while (m--)
    {
       int x,y;
       cin >> x >> y;
       line[x][y] = 1;
       line[y][x] = 1;
    }
    
    dfs(n, v);
    cout << endl;
    bfs(n,v);

    return 0;
}