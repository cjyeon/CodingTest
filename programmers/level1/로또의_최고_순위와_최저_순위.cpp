#include <string>
#include <vector>
using namespace std;

vector<int> answer;

void print(int data) {
    switch (data) {
        case 6 :
            answer.push_back(1);
            break;
        case 5 :
            answer.push_back(2);
            break;
        case 4 :
            answer.push_back(3);
            break;
        case 3 :
            answer.push_back(4);
            break;
        case 2 :
            answer.push_back(5);
            break;
        default :
            answer.push_back(6);
            break;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int rank_min = 0, rank_max = 0;
    
    for(int i = 0; i < lottos.size(); i++) {
        if(lottos[i] == 0) {
            rank_min++;
            continue;
        } 
        for(int j = 0; j < win_nums.size(); j++) {
            if(lottos[i] == win_nums[j]) {
                rank_min++;
                rank_max++;
            }
        }
    }
    
    print(rank_min);
    print(rank_max);
    
    return answer;
}