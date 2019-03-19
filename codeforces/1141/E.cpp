#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 2e5;
const ll MOD = 1e9 + 7;

ll tab[200010];

ll cei(ll x,ll y)
{
	return (x / y) + (x % y != 0);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll h,n;
	cin >> h >> n;
	ll tot = 0ll;
	for (ll i = 1 ; i <= n ; i++)
	{
		cin >> tab[i];
		tot += tab[i];
		if (tot * -1 >= h)
		{
			cout << i << endl;
			return 0;
		}
	}
	if (tot >= 0)
	{
		cout << -1 << endl;
		return 0;
	}
	ll l = 1ll;
	ll r = cei(h,-tot) + 3;
	while (l < r)
	{
		ll mid = (l + r) >> 1ll;
		// cout << mid << endl;
		ll kurang = (mid - 1) * tot;
		ll tmp = h;
		tmp += kurang;
		bool bisa = 0;
		if (tmp <= 0)
			bisa = 1;
		if (!bisa)
		{
			for (ll i = 1 ; i <= n ; i++)
			{
				tmp += tab[i];
				if (tmp <= 0)
				{
					bisa = 1;
					break;
				}
			}
		}
		if (bisa)
			r = mid;
		else
			l = mid + 1;
	}
	ll ronde = r;
	// cout << ronde << endl;
	ll kurang = (ronde - 1) * tot;
	h += kurang;
	ll ans = (ronde - 1) * n;
	for (ll i = 1 ; i <= n ; i++)
	{
		h += tab[i];
		++ans;
		if (h <= 0) break;
	}
	cout << ans << endl;
}