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

bool ada[110];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		memset(ada,0,sizeof(ada));
		int n;
		cin >> n;
		int gen = 0;
		int gan = 0;
		for (int i = 1 ; i <= n ; i++)
		{
			int ta;
			cin >> ta;
			ada[ta] = 1;
			gen += (ta % 2 == 0);
			gan += (ta % 2);
		}
		if (gen % 2 == 0 && gan % 2 == 0)
			cout << "YES\n";
		else
		{
			for (int i = 1 ; i + 1 <= 100 ; i++)
			{
				if (ada[i] && ada[i + 1])
				{
					cout << "YES\n";
					goto hell;
				}
			}
			cout << "NO\n";
			hell:;
		}
	}
	return 0;
}