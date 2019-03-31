#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 2e5;
const int MOD = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		sort(s.begin(),s.end());
		for (int i = 1 ; i < s.length() ; i++)
		{
			if (s[i] != s[i - 1] + 1)
			{
				cout << "NO\n";
				goto hell;
			}
		}
		cout << "YES\n";
		hell:;
	}	
}