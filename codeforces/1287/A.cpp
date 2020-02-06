#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string ta;
		cin >> ta;
		int res = 0;
		int cnt = 0;
		int i = 0;
		while (ta[i] == 'P') ++i;
		for ( ; i < n ; i++)
		{
			if (ta[i] == 'A')
			{
				res = max(res,cnt);
				cnt = 0;
			}
			else
			{
				++cnt;
			}
		}
		if (ta[n - 1] == 'P')
			res = max(res,cnt);
		cout << res << endl;
		
	}
	
}
