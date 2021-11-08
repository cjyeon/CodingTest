#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i < n; i++) {
        int a = arr1[i], b = arr2[i];
        string s = "";
        
        for(int j = n - 1; j > 0; j--) {
            ((a % 2) || (b % 2))? s = '#' + s : s = ' ' + s;
            a /= 2;
            b /= 2;
        }
        ((a % 2) || (b % 2))? s = '#' + s : s = ' ' + s;
        //비트연산자 '>>' 사용해서 개선 가능..
        answer.push_back(s);
    }
    
    return answer;
}