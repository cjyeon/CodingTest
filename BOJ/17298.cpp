#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vec(n), result(n, -1);  //마지막값 -1
    stack<int> st;

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    for (int i = 0; i < n; i++) 
    {
        while (!st.empty() && vec[st.top()] < vec[i])
        {
            result[st.top()] = vec[i];
            st.pop();
        }
        st.push(i);
    }
    
    for (int i:result)
    {
        cout << i << " ";
    }
    
    return 0;
}