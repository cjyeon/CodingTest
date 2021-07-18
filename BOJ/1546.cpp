#include <iostream>
using namespace std;

int main() {
    int n, max = 0;
    double sum = 0;
    cin >> n;
    double score[n];

    for (int i = 0; i < n; i++)
    {
        cin >> score[i];
        if (score[i] >= max) max = score[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        score[i] = (score[i]/max) * 100;
        sum += score[i];
    }
    cout << sum / n ;
}