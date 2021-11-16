#include <iostream>
using namespace std;

int main() {
    int visited[101][101] = {0,};
    int n, answer = 0;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        for(int i = a+1; i <= 10 + a; i++) {
            for(int j = b+1; j <= 10 + b; j++) {
                visited[i][j]++;
            }
        }
    }
    
    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= 100; j++) {
            if(visited[i][j] > 0) answer++;
        }
    }

    cout << answer;

    return 0;
}