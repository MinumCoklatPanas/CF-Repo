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
	ll n;
	cin >> n;
	for (ll i = 1 ; i <= n ; i++)
		cin >> tab[i];
	ll ans = INFF;
	for (ll i = 1 ; i <= n ; i++)
	{
		ll cur = tab[i];
		ll cnt = 0;
		for (ll j = 1 ; j <= n ; j++)
		{
			ll jarak = abs(tab[i] - tab[j]);
			cnt += (jarak % 2);
		}
		ans = min(ans,cnt);
	}
	cout << ans << endl;
}