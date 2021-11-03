#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 51;
int m, n, k, answer;
bool graph[MAX][MAX] = {0};
bool visited[MAX][MAX];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y)
{
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= n || nx < 0 || ny >= m || ny < 0)
            continue;

        if (graph[nx][ny] && !visited[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--) {
        cin >> m >> n >> k;
        answer = 0;
        memset(visited, 0, sizeof(visited));
        memset(graph, 0, sizeof(graph));

        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            graph[b][a] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (graph[i][j] && !visited[i][j]) {
                    answer++;
                    dfs(i, j);
                }
            }
        }

        cout << answer << '\n'; 
    }

    return 0;
}