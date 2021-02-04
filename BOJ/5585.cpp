#include <iostream>
using namespace std;

int main()
{
    int n1, n2, result = 0, arr[6]= {500, 100, 50, 10, 5, 1};
    cin >> n1;
    n2 = 1000 - n1;

    for (int i = 0; n2 > 0;)
    {
        if (n2 >= arr[i])
        {
            result += n2 / arr[i];
            n2 %= arr[i];
        }
        else
            i++;
    }

    cout << result;

    return 0;
}
