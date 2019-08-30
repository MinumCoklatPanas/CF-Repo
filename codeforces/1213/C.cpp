#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;

ll tab[15];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll q;
	cin >> q;
	while (q--)
	{
		ll n,m;
		cin >> n >> m;
		ll tot = 0ll;
		for (ll i = 1 ; i <= 10 ; i++)
		{
			tab[i] = (i * m) % 10;
			tot += tab[i];
		}
		ll banyak = n / m;
		ll ans = (banyak / 10) * tot;
		for (ll i = 1 ; i <= (banyak % 10) ; i++)
			ans += tab[i];
		cout << ans << endl;
	}
}