#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 101
int graph[MAX][MAX][MAX];
int visited[MAX][MAX][MAX];
int M, N, H, answer = 0, flag = 0;
int dx[] = {0, 0, 0, 0, 1, -1};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {1, -1, 0, 0, 0 ,0};
queue<pair<int, pair<int, int>>> q;


int main() {
    cin >> M >> N >> H;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> graph[i][j][k];
                if(graph[i][j][k] == 1) q.push({i, {j, k}});
                if(graph[i][j][k] == 0) visited[i][j][k] = -1;
            }
        }
    }
    
    while (!q.empty()) {
        int z = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nz = z + dz[i];
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nz < 0 || nz >= H || nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(visited[nz][nx][ny] >= 0) continue;
            
            visited[nz][nx][ny] = visited[z][x][y] + 1;
            q.push({nz, {nx, ny}});
        }
    }
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if(visited[i][j][k] == -1) {
                    cout << -1;
                    return 0;
                }
                answer = max(answer, visited[i][j][k]);
            }
        }
    }

    cout << answer;

    return 0;
}