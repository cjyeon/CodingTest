#include <iostream>
#include <queue>
using namespace std;

int n, m;
int maze[101][101];
// 상하좌우
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(int x, int y) {
    queue< pair<int,int> > q;

    q.push(make_pair(x,y));

    while (!q.empty())
    {
        int x = q.front().first; 
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if (maze[nx][ny] == 0) continue;

            // 해당 노드 처음 방문 시에만 거리 기록
            if (maze[nx][ny] == 1)
            {
                maze[nx][ny] = maze[x][y] + 1;
                q.push(make_pair(nx,ny));
            }
        }
    }
    return maze[n-1][m-1];
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &maze[i][j]);  // 한글자씩 입력
        }
    }
    cout << bfs(0,0) << endl;

    return 0;
}