#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;

bool ada[1000010];
ll tab[310];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	while (t--)
	{
		memset(ada,0,sizeof(ada));
		ll n;
		cin >> n;
		for (ll i = 1 ; i <= n ; i++)
		{
			cin >> tab[i];
			ada[tab[i]] = 1;
		}
		sort(tab + 1,tab + n + 1);
		ll now = tab[1] * tab[n];
		ll l = 1;
		ll r = n;
		bool yes = 1;
		while (l <= r)
		{
			ll tmp = tab[l] * tab[r];
			// cout << l << " " << r << endl;
			// cout << tmp << endl;
			if (tmp != now)
			{
				yes = 0;
				break;
			}
			++l;
			--r;
		}
		if (!yes)
			cout << -1 << endl;
		else
		{
			for (ll i = 2 ; i * i <= now ; i++) if (now % i == 0)
			{
				if (!ada[i])
				{
					yes = 0;
					break;
				}
				if (!ada[now / i])
				{
					yes = 0;
					break;
				}
			}
			// yes = 1;
			if (!yes)
				cout << -1 << endl;
			else
				cout << now << endl;
		}
	}
}