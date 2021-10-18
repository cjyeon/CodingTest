#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, answer = 0;
    cin >> n;

    int A[n], B[n];
    for(int i = 0; i < n; i++)
        cin >> A[i];

    for(int i = 0; i < n; i++)
        cin >> B[i];

    sort(A, A + n);
    sort(B, B + n);

    for (int i = 0; i < n; i++) {
        answer += A[n-1-i] * B[i];
    }
    
    cout << answer;

    return 0;
}