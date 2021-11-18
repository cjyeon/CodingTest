#include <iostream>
using namespace std;

int N, answer = 0;

void solution(int a, int b) {
    a += b;
    if(a == N) answer++;
    else if(a < N) {
        solution(a, 1);
        solution(a, 2);
        solution(a, 3);
    }
}

int main() {
    int k;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> N;
        solution(0, 0);
        cout << answer << '\n';
        answer = 0;
    }

    return 0;
}