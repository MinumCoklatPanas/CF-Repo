#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int empat = -1;
	int tujuh = -1;
	int len = 1e9;
	for (int i = 0 ; 4 * i <= n ; i++)
	{
		int sisa = n - 4 * i;
		if (sisa % 7 == 0)
		{
			int sum = i + sisa / 7;
			if (sum < len)
			{
				empat = i;
				tujuh = sisa / 7;
				len = sum;
			}
			else
			if (sum == len && empat > i)
			{
				empat = i;
				tujuh = sisa / 7;
				len = sum;
			}
		}
	}
	if (empat == -1)
		cout << -1 << endl;
	else
	{
		for (int i = 1 ; i <= empat ; i++)
			cout << 4;
		for (int i = 1 ; i <= tujuh ; i++)
			cout << 7;
		cout << endl;
	}
}