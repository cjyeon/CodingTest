#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue< pair<int, int> > que;
    priority_queue<int> pq;

    for (int i = 0; i < priorities.size(); i++)
    {
        que.push(make_pair(priorities[i], i));

        pq.push(priorities[i]);
    }

    while(!pq.empty()) {
        if (que.front().first == pq.top())
        {
            ++answer;
            if (que.front().second == location) break;

            que.pop();
            pq.pop();
        }
        else {
            que.push(make_pair(que.front().first, que.front().second));
            que.pop();
        }

    }
    
    return answer;
}