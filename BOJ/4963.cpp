#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define MAX 50
int graph[MAX][MAX];
bool visited[MAX][MAX];
int w, h;
int dx[] = {-1,0,1,-1,1,-1,0,1};
int dy[] = {1,1,1,0,0,-1,-1,-1};

void bfs(int x, int y) {
    queue< pair<int, int> > q;
    q.push(make_pair(x, y));
    visited[x][y] = 1;
    
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;

            if (graph[nx][ny] && !visited[nx][ny]) {
                visited[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}
 
void dfs(int x, int y) {
    visited[x][y] = true;

    for(int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
        
        if(graph[nx][ny] && !visited[nx][ny])
            dfs(nx, ny);
    }
}
 
int main() {
    while(true){
        memset(graph, 0, sizeof(graph));
        memset(visited, false, sizeof(visited));
        int answer = 0;

        cin >> h >> w;
        if(h == 0 && w == 0) break;
        for(int i = 0; i < w; i++){
            for(int j = 0; j < h; j++){
                cin >> graph[i][j];
            }
        }

        for(int i = 0; i < w; i++){
            for(int j = 0; j < h; j++){
                if(graph[i][j] && !visited[i][j]){
                    answer++;
                    bfs(i, j);
                }
            }
        }
        cout << answer << '\n';
    }
 
    return 0;
}
