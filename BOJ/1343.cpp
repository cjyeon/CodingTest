#include <iostream>
#include <string>
using namespace std;

int main()
{
	string n, result;
    int i = 0, cnt = 0;
 
	cin >> n;
 
	if (n.size() == 1 && n[0]=='X') {
        cout << -1 << endl;
		return 0;
	}
 
	while (n[i] != '\0') {
		while (n[i] == 'X' || n[i] != '.') {
			i++;
			cnt++;
 
			if (n[i] == '\0')
				break;
		}
 
		if (cnt % 2 == 0) {
			while (cnt >= 4) {
				result += "AAAA";
				cnt -= 4;
			}
			while (cnt >= 2) {
				result += "BB";
				cnt -= 2;
			}
		}
 
		if (cnt != 0) {
			cout << -1 << endl;
			return 0;
		}
		if (n[i] == '.') {
			result += ".";
			i++;
		}
	} 
	cout << result << endl;

	return 0;
}