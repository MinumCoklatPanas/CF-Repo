#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

ll cnt(ll x) {
	return (x * (x + 1)) / 2;
}

ll rec(ll x,ll y,ll step) {
	// cout << x << " " << y << endl;
	if (abs(x - y) > 25) return INF;
	if (x == y) return 0;
	return 1 + min(rec(x + step,y,step + 1),rec(x,y + step,step + 1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		ll a,b;
		cin >> a >> b;
		ll diff = abs(a - b);
		ll l = 0;
		ll r = 1000000000;
		while (r - l > 1) {
			ll mid = (l + r) / 2;
			ll ret = cnt(mid);
			if (ret <= diff)
				l = mid;
			else
				r = mid - 1;
		}
		ll smol;
		if (cnt(r) <= diff)
			smol = r;
		else
			smol = l;
		ll ans = smol + (cnt(smol) != diff);
		while ((cnt(ans) - diff) % 2 != 0)
			++ans;
		// ll rem = diff - cnt(smol);
		// ans += rem * 2;
		cout << ans << endl;
	}
}