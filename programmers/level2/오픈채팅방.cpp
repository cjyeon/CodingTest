#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer, message;
    map<string, string> user;
    
    for(int i = 0; i < record.size(); i++) {
        stringstream ss(record[i]);
        string result[3], temp;
        int index = 0;
        
        while(ss >> temp)
            result[index++] = temp;
        
        if(result[0] == "Enter")  {
            message.push_back("님이 들어왔습니다.");
            user[result[1]] = result[2];
            answer.push_back(result[1]);
        }
        else if(result[0] == "Leave") {
            message.push_back("님이 나갔습니다.");
            answer.push_back(result[1]);
        }
        else {
            user[result[1]] = result[2];
        }
    }
    
    for(int i = 0; i < answer.size(); i++)
        answer[i] = user[answer[i]] + message[i];
    
    return answer;
}