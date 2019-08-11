#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;

ll tab[110];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	while (t--)
	{
		ll	n,m,k;
		cin >> n >> m >> k;
		for (ll i = 1 ; i <= n ; i++)
		{
			cin >> tab[i];
		}
		for (ll i = 1 ; i < n ; i++)
		{
			ll harusnya = max(0ll,tab[i + 1] - k);
			if (tab[i] >= harusnya)
			{
				m += tab[i] - harusnya;
			}
			else
			{
				ll butuh = harusnya - tab[i];
				if (butuh > m)
				{
					cout << "NO\n";
					goto hell;
				}
				m -= butuh;
			}
		}
		cout << "YES\n";
		hell:;
	}
}