#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int k, num, now = 1;
    string s = "";
    stack<int> st;
    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> num;
        if (num >= now) {
            for (int j = now; j <= num; j++) {
                st.push(j);
                s += '+';
                if (num == st.top()) {
                    st.pop();
                    s += '-';
                }
                now++;
            }
        } else {
            if (num == st.top())
            {
                st.pop();
                s += '-';
            } else {
                cout << "NO" << '\n';
                return 0;
            }
        }
    }

    for (int i = 0; i < s.size(); i++)
        cout << s[i] << '\n';
}