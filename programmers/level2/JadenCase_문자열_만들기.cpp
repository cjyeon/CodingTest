#include <string>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    bool flag = true;
    
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') {
            answer += s[i];
            flag = true;
            continue;
        } else if(flag == true) {
            answer += toupper(s[i]);
        } else answer += tolower(s[i]);
        flag = false;
    }
    
    return answer;
}