#include <iostream>
using namespace std;

int A, B;
long long answer;

void solution(long long num) {
        if (num > B) return;

        if (A <= num && num <= B) answer++;

        solution(num * 10 + 4);
        solution(num * 10 + 7);
}

int main(void) {
        cin >> A >> B;

        solution(4);
        solution(7);

        cout << answer << "\n";

        return 0;

}