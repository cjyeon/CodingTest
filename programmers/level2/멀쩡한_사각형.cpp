using namespace std;

int GCD(int a, int b) {
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long solution(int w,int h) {
    long long answer = (long long)w * (long long)h - (w + h) + GCD(w, h);
    
    return answer;
}