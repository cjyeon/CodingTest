#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> trees) {
    int answer = 0;
    
    while(!trees.empty()) {
        string tmp;
        bool flag = 0;
        string s = trees.back();
        trees.erase(trees.begin() + (trees.size()-1));
        
        for(int i = 0; i < s.size(); i++) {
            for(int j = 0; j < skill.size(); j++) {
                if(s[i] == skill[j]) {
                    tmp += s[i];
                }
            }
        }
        
        for(int i = 0; i < tmp.size(); i++) {
            if(skill[i] != tmp[i]) flag = 1;
        }
        
        if(!flag) answer++;
    }
    
    return answer;
}