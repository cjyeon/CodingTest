#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b) {
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int LCM(int a, int b) {
    return a * b / GCD(a, b);
}

int solution(vector<int> arr) {
    int tmp = arr.front();
    arr.erase(arr.begin() + 0);
    
    while(!arr.empty()) {
        int a = arr.front();
        arr.erase(arr.begin() + 0);
        tmp = LCM(a, tmp);
    }
    
    return tmp;
}