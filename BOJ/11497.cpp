#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int test, n;
    cin >> test;

    for (int i = 0; i < test; i++)
    {
        cin >> n;
        int wood[n];

        for (int j = 0; j < n; j++)
        {
            cin >> wood[j];
        }
        sort(wood, wood + n);

        int result = 0;
		for (int k = 2; k < n; k++) {
			result = max(result, wood[k] - wood[k - 2]);
		}
		cout << result << endl;
    }
    return 0;
}