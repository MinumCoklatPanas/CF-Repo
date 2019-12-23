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

ll n;

ll cnt(ll diff) {
	ll tot = (n + (diff - 1)) / diff;
	ll last = (diff * (tot - 1)) + 1;
	ll sum = ((1 + last) * (tot)) / 2;
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	set<ll> ans;
	for (ll i = 1 ; i * i <= n ; i++) if (n % i == 0) {
		ll rem = n / i;
		ans.insert(cnt(i));
		ans.insert(cnt(rem));
	}
	for (auto it : ans)
		cout << it << " ";
	cout << endl;
}