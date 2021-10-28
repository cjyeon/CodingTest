#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> set_tmp;
    
    for(int i = 0; i < numbers.size(); i++) {
        for(int j = i+1; j < numbers.size(); j++) {
            set_tmp.insert(numbers[i] + numbers[j]);
        }
    }
    
    for(auto s : set_tmp) {
        answer.push_back(s);
    }
    
    return answer;
}