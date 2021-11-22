#include <string>
#include <vector>

using namespace std;

const int MAX = 100001;

int solution(int n) {
    int answer = 0;
    int fib[MAX];
    fib[0] = 0, fib[1] = 1;
    
    for(int i = 2; i <= n; i++) {
        fib[i] = (fib[i-1] + fib[i-2]) % 1234567;
    }
   
    answer = fib[n];
    
    return answer;
}