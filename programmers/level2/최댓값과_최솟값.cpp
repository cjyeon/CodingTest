#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    string tmp;
    vector<int> vec;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') {
            vec.push_back(stoi(tmp));
            tmp.clear();
        } else {
            tmp += s[i];
        }
    }
    vec.push_back(stoi(tmp));
    sort(vec.begin(), vec.end());
    
    answer += to_string(vec.front()) + " " + to_string(vec.back());
    
    return answer;
}