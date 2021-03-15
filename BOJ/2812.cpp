#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k, i;
    char num[500001];
    deque<char> dq;
    cin >> n >> k;
    scanf("%s", num);

    for (i = 0; i < n; i++) {
        while(k > 0 && !dq.empty() && dq.back() < num[i]) {
            dq.pop_back();
            k--;
            // 이전 값이 입력하려는 값보다 작으면 삭제하고 입력(k번)
        }
        dq.push_back(num[i]);
    }

    for (i = 0; i < dq.size() - k; i++) {
        cout << dq[i];
    }

    return 0;
}