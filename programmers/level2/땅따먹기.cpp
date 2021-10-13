#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxNum(int a, vector<int> v) {
    int now = 0;
    for(int i = 0; i < 4; i++) {
        if(i != a && v[i] > now) {
            now = max(now, v[i]);
        }
    }
    return now;
}

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int i;
    
    for(i = 1; i < land.size(); i++) {
        for(int j = 0; j < 4; j++) {
            land[i][j] += maxNum(j, land[i-1]);
            answer = max(answer, land[i][j]);
        }
    }
    return answer;
}