#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[1001], word[5] = "UCPC";
    int count = 0;
    cin.getline(s, 1001);

    for (int i = 0; i < strlen(s); i++) {
        if (count == 4) {
            break;
        }
        else if (s[i] == word[count]) {
            count++;
        }
    }

    if (count == 4) {
        cout << "I love UCPC";
    }
    else
        cout << "I hate UCPC";
}