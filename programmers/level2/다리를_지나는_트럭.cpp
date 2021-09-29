#include <string>
#include <deque>
#include <vector>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum = 0;
    deque<int> dq;

    while(1)
    {
        if(truck_weights.empty()) {
            answer += bridge_length;
            break;
        }
        
        ++answer;
        
        if (dq.size() == bridge_length) {
            sum -= dq.back();
            dq.pop_back();
        }
    
        if (sum + truck_weights[0] <= weight)
        {
            dq.push_front(truck_weights[0]);
            sum += dq.front();
            truck_weights.erase(truck_weights.begin() + 0);
        } else {
            dq.push_front(0);
        }
    }

    return answer;
}