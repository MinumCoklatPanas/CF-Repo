#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;

priority_queue< ll,vector<ll>,greater<ll> > step[200010];
ll tab[200010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,k;
	cin >> n >> k;
	for (ll i = 1 ; i <= n ; i++)
		cin >> tab[i];
	for (ll i = 1 ; i <= n ; i++)
	{
		ll cnt = 0;
		ll awal = tab[i];
		while (tab[i])
		{
			step[tab[i]].push(cnt);
			++cnt;
			tab[i] /= 2;
		}
		step[tab[i]].push(cnt);
	}
// 	return 0;
	ll ans = INFF;
	for (ll i = 1 ; i <= 200000 ; i++) if (step[i].size() >= k)
	{
		ll cnt = 0;
		for (ll j = 1 ; j <= k ; j++)
		{
			cnt += step[i].top();
			step[i].pop();
		}
		ans = min(ans,cnt);
	}
	cout << ans << endl;
}