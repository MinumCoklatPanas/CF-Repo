#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
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
		int n;
		cin >> n;
		string s;
		cin >> s;
		int pertama = -1;
		for (int i = 0 ; i < n ; i++)
		{
			if (s[i] == '8')
			{
				pertama = i;
				break;
			}
		}
		if (pertama == -1)
			cout << "NO\n";
		else
		{
			int kurang = n - 11;
			if (pertama <= kurang)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}