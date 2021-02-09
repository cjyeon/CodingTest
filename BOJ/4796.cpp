#include <iostream>
using namespace std;

int main()
{
    int l, p, v, result;
    int i = 1;

    while (true)
    {
        result = 0;
        cin >> l >> p >> v;

        if (l == 0 && p == 0 && v == 0)
            break;

        result = (v / p) * l;
        result += v%p > l ? l : v%p;
        cout << "Case " << i << ": " << result << endl;
        i++;
    }

    return 0;
}