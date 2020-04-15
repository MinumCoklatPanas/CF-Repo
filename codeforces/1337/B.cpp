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
		int x,n,m;
		cin >> x >> n >> m;
		for (int i = 0 ; i <= n ; i++)
		{
			int tmp = (x / 10) + (x % 10 != 0);
			if  (tmp <= m)
			{
				// cout << x << endl;
				cout << "YES\n";
				goto hell;
			}
			x = (x / 2) + 10;
		}
		cout << "NO\n";
		hell:;
	}
	return 0;
}