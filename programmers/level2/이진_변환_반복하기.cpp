#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int change = 0, zero = 0;
    
    while (s != "1") {
        change++;
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                zero++;
                s.erase(s.begin() + i);
                i--;
            }
        }
        if(s == "1") break; 

        int a = s.size();
        s.clear();
        while(a > 0) {
            if(a % 2 == 1) s.push_back('1');
            else s.push_back('0');
            a /= 2;
        }
        reverse(s.begin(), s.end());
    }
    
    answer.push_back(change);
    answer.push_back(zero);
    
    return answer;
}