#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool compare(char a, char b) {
    if(a > b) return true;
    return false;
}

int main() {
    string num;
    cin >> num;
    long long sum = 0;
    bool flag = false;

    //30의 배수는 뒷자리 0이고, 모든 자릿수 합이 3의 배수여야 함

    for(int i = 0; i < num.size(); i++) {
        sum += (num[i] - '0');
        if((num[i] - '0') == 0) flag = true;
    }

    if(!flag || sum % 3) cout << -1;
    else {
        sort(num.begin(), num.end(), compare);
        cout << num;
    }

    return 0;
}