#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100;
int n, a = 0, b = 0;
char graph[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void dfs(int x, int y) {
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

        if(graph[x][y] == graph[nx][ny] && !visited[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(!visited[i][j]) {
                dfs(i, j);
                a++;
            }
        }
    }

    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(graph[i][j] == 'G') graph[i][j] = 'R';
            else continue;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(!visited[i][j]) {
                dfs(i, j);
                b++;
            }
        }
    }
    cout << a << '\n' << b << '\n';

    return 0;
}