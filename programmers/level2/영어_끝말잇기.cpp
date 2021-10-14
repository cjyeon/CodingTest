#include <string>
#include <vector>
 
using namespace std;
 
vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    bool flag = 0;
    int a = 0;
    int b = 0;
    
    for(int i = 1; i < words.size(); i++){
        string pre = words[i-1];
        string now = words[i];
        
        for(int j = 0; j < i; j ++){
            if(words[j] == words[i]){
                flag = 1;
                break;
            }
        }
        
        if(pre[pre.length() - 1] != now[0])
            flag = 1;

        if(flag){
            a = (i % n) + 1;
            b = (i / n) + 1;
            answer.push_back(a);
            answer.push_back(b);
            
            return answer;
        }
    }

    answer.push_back(0);
    answer.push_back(0);
    return answer;
}