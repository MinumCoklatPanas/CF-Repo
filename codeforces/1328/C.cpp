#include <bits/stdc++.h>
using namespace std;
 
//Made with <3 by MinumCoklatPanas
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string s,a,b;
		cin >> s;
		bool can = 0;
		if (s[0] == '0')
		{
			a += '2',b += '1';
			can = 1;
		}
		else
		if (s[0] == '1')
			a += '2', b += '2';
		else
			a += '1', b += '1';
		for (int i = 1 ; i < n ; i++)
		{
			if (s[i] == '0')
				a += '0',b += '0';
			else
			if (s[i] == '1')
			{
				if (!can)
				{
					a += '1',b += '0';
					can = 1;
				}
				else
					a += '0', b += '1';
			}
			else
			if (s[i] == '2')
			{
				if (!can)
					a += '1',b += '1';
				else
					a += '0', b += '2';
			}
		}
		cout << a << endl;
		cout << b << endl;
	}
	return 0;
}