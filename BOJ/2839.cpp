#include <iostream>
using namespace std;

int main()
{
    int n, m, remain, result;
    cin >> n;

    m = n / 5;
    while (m >= 0)
    {
        remain = 0;
        result = 0;
        if (m > 0)
        {
            remain = n - 5 * m;
            result = m;
        }
        else
            remain = n;
        result += remain / 3;
        remain %= 3;

        if (remain == 0)
        {
            cout << result;
            break;
        }
        m--;
    }
    if (remain != 0)
    {
        cout << -1;
    }

    return 0;
}
