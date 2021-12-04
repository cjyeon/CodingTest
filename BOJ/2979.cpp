#include <iostream>
using namespace std;

int A, B, C, answer = 0;
int arr[101];

int main() {
    cin >> A >> B >> C;

    for (int i = 0; i < 3; i++)
    {
        int start, end;
        cin >> start >> end;

        for (int j = start; j < end; j++)
        {
            arr[j]++;
        }
    }
    
    for (int i = 1; i < 101; i++)
    {
        if (arr[i] == 1) answer += arr[i] * A;
        else if (arr[i] == 2) answer += arr[i] * B;
        else answer += arr[i] * C;
    }
    cout << answer;

    return 0;
}