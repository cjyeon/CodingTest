#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, ans;
    int triangle[501][501];
    int result[501][501];

    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> triangle[i][j];
        }
    }
    result[0][0] = triangle[0][0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n ; j++) {
            if (j == 0)
                result[i][j] = result[i-1][j] + triangle[i][j];
            else if(j == i)
                result[i][j] = result[i-1][j-1] + triangle[i][j];
            else 
                result[i][j] = max(result[i-1][j-1], result[i-1][j]) + triangle[i][j];   
        }
    }
    
    ans = 0;
    for (int i = 0; i < n; i++) {
        if(result[n-1][i] >= ans) 
            ans = result[n-1][i];
    }

    cout << ans << endl;

    return 0;
}