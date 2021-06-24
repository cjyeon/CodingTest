#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;
    int k, n, answer = 0;
    cin >> k;

    while (k--)
    {
        cin >> n;

        if (n != 0) {
            st.push(n);
            answer += n;
        }
        else {
            answer -= st.top();
            st.pop();
        }
    }

    cout << answer << endl;
    
    return 0;
}