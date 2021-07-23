#include <iostream>
#include <queue>
using namespace std;
 
int box[1001][1001];
int M, N;
 
queue< pair<int, int> > q;
 
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
 
void bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx <= 0 || nx > N || ny <= 0 || ny > M) continue;
            if(box[nx][ny] == 0){
                box[nx][ny] = box[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}
 
int main() {
    cin >> M >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> box[i][j];
            if(box[i][j] == 1)
                q.push(make_pair(i, j));
        }
    }
    
    bfs();
    
    int max = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(box[i][j] == 0){
                cout << "-1" << endl;
                return 0;
            }
            
            if(max < box[i][j])
                max = box[i][j];
        }
    }
    cout << max-1 << endl;
    
    return 0;
}