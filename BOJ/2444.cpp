#include <iostream>
using namespace std;

int main()
{
	int n, m = 1;
	cin >> n;

    for (int i = 1; i <= n-1; i++)  
	{
		for (int j = n-i; j > 0; j--)  
		{
			cout << " ";
		}
		for (int k = 1; k <= m; k ++) 
		{
			cout << "*";
		}
		m += 2;
		cout << endl;
	}

	for (int i = 1; i <= n; i++)  
	{
        for (int j = 1; j <= i-1; j++)  
		{
			cout << " ";
		}
		for (int k = 1; k <= m; k++)  
		{
			cout << "*";
		}
		m -= 2;
		cout << endl;
	}

	return 0;
}