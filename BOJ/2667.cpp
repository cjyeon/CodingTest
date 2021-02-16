#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n, cnt = 0;
int house[25][25];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool visited[25][25];
vector<int> cnt_vec;

void dfs(int x, int y) {
	cnt++;
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

		if (house[nx][ny]&& !visited[nx][ny]){
			dfs(nx, ny);
		}
	}
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%1d", &house[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (house[i][j] && !visited[i][j])  // 모든 노드들 중 1이면서 처음 방문하는 노드일 경우 탐색
            {
                cnt=0;
                dfs(i, j);
                cnt_vec.push_back(cnt);
            }
        }
    }
    sort(cnt_vec.begin(), cnt_vec.end());

    cout << cnt_vec.size() << endl;
    for (int i = 0; i < cnt_vec.size(); i++)
    {
        cout << cnt_vec[i] << endl;
    }

    return 0;
}