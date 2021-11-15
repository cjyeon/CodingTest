#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, L, time = 1;
    cin >> N >> L;
    vector<vector<int>> vec(N, vector<int>(3));

    for (int i = 0; i < N; i++)
        cin >> vec[i][0] >> vec[i][1] >> vec[i][2];

    for (int i = 1; i <= L; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int D = vec[j][0];
            int R = vec[j][1];
            int G = vec[j][2];
            if (i == D && time % (R + G) < R)
            {
                time += R - time % (R + G);
            }
        }
        time++;
    }
    cout << time - 1;

    return 0;
}