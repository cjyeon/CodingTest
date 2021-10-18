#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";

    for (int i = 0; i < scores.size(); i++) {
        int size = scores.size();
        vector<int> student;
        int self = scores[i][i];
        
        for (int j = 0; j < size; j++) 
            student.push_back(scores[j][i]);

        int min = *min_element(student.begin(), student.end());
	    int max = *max_element(student.begin(), student.end());

        sort(student.begin(), student.end());
        
        if(self == max) {
            if(student[size-1] != student[size-2]) {
                student.erase(student.begin() + (size-1));
                size--;
            }
        }
        else if(self == min) {
            if(student[0] != student[1]) {
                student.erase(student.begin() + 0);
                size--;
            }
        }

        int sum = 0, avg;

        for (auto s : student) 
            sum += s;

        avg = sum / size;
        avg /= 10;

        switch (avg) {
        case 9:
            answer += 'A';
            break;
        case 8:
            answer += 'B';
            break; 
        case 7:
            answer += 'C';
            break;    
        case 6:
        case 5:
            answer += 'D';
            break;    
        default:
            answer += 'F';
            break;
        }
    }

    return answer;
}