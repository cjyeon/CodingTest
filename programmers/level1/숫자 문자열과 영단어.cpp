#include <string>
using namespace std;

int solution(string s) {
    int answer = 0;
    string str = "";

    for(int i = 0; i < s.size(); i++) {
        if('0' <= s[i] && s[i] <= '9') {
            str.push_back(s[i]);
            continue;
        }
        int size = s.size() - i;
        if(size >= 5 && s.substr(i,5)=="three") str.push_back('3');
        else if(size >= 5 && s.substr(i,5)=="seven") str.push_back('7');
        else if(size >= 5 && s.substr(i,5)=="eight") str.push_back('8');
        else if(size >= 4 && s.substr(i,4)=="zero") str.push_back('0');
        else if(size >= 4 && s.substr(i,4)=="four") str.push_back('4');
        else if(size >= 4 && s.substr(i,4)=="five") str.push_back('5');
        else if(size >= 4 && s.substr(i,4)=="nine") str.push_back('9');
        else if(size >= 3 && s.substr(i,3)=="one") str.push_back('1');
        else if(size >= 3 && s.substr(i,3)=="two") str.push_back('2');
        else if(size >= 3 && s.substr(i,3)=="six") str.push_back('6');            
    }
    
    answer = stoi(str);
    return answer;
}