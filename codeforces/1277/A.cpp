#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, pair<ll, ll> > piii;
#define pb push_back
#define debug(x) cout << x << endl
#define NeedForSpeed ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 5;
const ll INF64 = 1e18;
 
const ll N = 1e5 + 5;

ll cnt(ll x) {
	ll ret = 0;
	while (x) {
		ret++;
		x /= 10;
	}
	return ret;
}

int main() {
	NeedForSpeed;
	ll t;
	cin >> t;
	while (t--) {
		ll ta;
		cin >> ta;
		ll dig = cnt(ta);
		ll ans = (dig - 1) * 9;
		ll rid = 0;
		for (ll i = 1 ; i <= dig ; i++) {
			rid *= 10;
			rid++;
		}
		ans += ta / rid;
		cout << ans << endl;
	}
	return 0;
}