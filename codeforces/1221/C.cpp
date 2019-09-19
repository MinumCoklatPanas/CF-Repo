#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;

ll cnt(ll c,ll m)
{
	cout << c << " " << m << endl;
	if (c == 0 || m == 0) return 0;
	if (c + m < 3) return 0;
	if (c < m)
		swap(c,m);
	ll ret = min(c / 2,m);
	c -= 2 * ret;
	m -= ret;
	return ret + cnt(c,m);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll q;
	cin >> q;
	while (q--)
	{
		ll c,m,x;
		cin >> c >> m >> x;
		// ll ans2 = cnt(c,m);
		ll mn = min(min(c,m),x);
		ll ans = mn;
		c -= mn;
		m -= mn;
		x -= mn;
		// ans += cnt(c,m);
		ans += min(min(c,m),(c + m) / 3);
		// ans = max(ans,ans2);
		cout << ans << endl;
	}
}