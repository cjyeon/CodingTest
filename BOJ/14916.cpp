#include <iostream>
using namespace std;

int main()
{
    int sum, result = 0;
    cin >> sum;

    if (sum != 1 && sum != 3)
    {
        while (sum > 0)
        {
            if (sum >= 5)
            {
                result += sum / 5;
                sum %= 5;
            }
            else
            {
                if (sum % 2 == 0)
                {
                    result += sum / 2;
                    break;
                }
                else
                {
                    result--;
                    result += (sum + 5) / 2;
                    break;
                }
            }
        }
    } else result = -1;

    cout << result << endl;

    return 0;
}