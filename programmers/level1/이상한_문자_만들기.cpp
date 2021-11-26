#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int j = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') {
            j = 0;
            answer += s[i];
            continue;
        }
        else {
            if(j % 2 == 0) {
                if(s[i] >= 'a' && s[i] <= 'z') answer += s[i] - 32;
                else answer += s[i];
            }
            else if(j % 2 != 0) {
                if(s[i] >= 'A' && s[i] <= 'Z') answer += s[i] + 32;
                else answer += s[i];
            } 
        }
        j++;
    }
    
    return answer;
}