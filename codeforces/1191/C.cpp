#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;

ll cei(ll a,ll b)
{
	if (a <= 0) return 0;
	return ((a / b) + (a % b != 0));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m,k;
	cin >> n >> m >> k;
	queue< ll > q;
	for (ll i = 1 ; i <= m ; i++)
	{
		ll ta;
		cin >> ta;
		q.push(ta);
	}
	ll curLast = k;
	ll ans = 0;
	while (!q.empty())
	{
		ll cnt = 0;
		// cout << curLast << " "  << q.front() << endl;
		while (!q.empty() && q.front() <= curLast)
		{
			++cnt;
			q.pop();
		}
		curLast = min(n,curLast + cnt);
		if (!q.empty())
		{
			ll x = max(0ll,cei((q.front() - curLast),k));
			// cout << x << endl;
			curLast = curLast + k * x;
		}
		ans += (cnt > 0);
	}
	cout << ans << endl;
}