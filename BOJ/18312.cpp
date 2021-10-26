#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, answer = 0;
    char K;
    cin >> N >> K;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < 60; j++) {
            for (int k = 0; k < 60; k++) {
                string s;
                if (i / 10 == 0) s += "0";
				s += to_string(i);
                
                if (j / 10 == 0) s += "0";
				s += to_string(j);

				if (k / 10 == 0) s += "0";
                s += to_string(k);
                
                if (s.find(K) != -1) answer++;
            }
        }
    }
    cout << answer;

    return 0;
}