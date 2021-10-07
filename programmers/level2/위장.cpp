#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> result;
    
    for (auto c: clothes)
        result[c[1]]++;
    
    for (auto i = result.begin(); i != result.end(); i++) {
        answer *= i -> second + 1;
    }    
        
    return answer - 1;
}