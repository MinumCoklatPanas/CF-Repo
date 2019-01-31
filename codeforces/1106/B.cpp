#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 100010;
const ll MOD = 1e9 + 7;

#define cost first
#define ix second

ll frek[MAXN];
ll c[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin >> n >> m;
	ll tot = 0;
	for (ll i = 1 ; i <= n ; i++)
	{
		cin >> frek[i];
		tot += frek[i];
	}
	priority_queue< pair<ll,ll> > pq;
	for (ll i = 1 ; i <= n ; i++)
	{
		ll a;
		cin >> a;
		c[i] = a;
		pq.push(make_pair(-a,-i));
	}
	while (m--)
	{
		ll index,cnt;
		cin >> index >> cnt;
		if (tot < cnt)
		{
			tot = 0;
			cout << 0 << endl;
			continue;
		}
		tot -= cnt;
		// cout << index << " " << cnt << endl;
		if (frek[index] >= cnt)
		{
			ll ans = c[index] * cnt;
			frek[index] -= cnt;
			cout << ans << endl;
		}
		else
		{
			ll ans = c[index] * frek[index];
			// cout << c[index] << " " << frek[index] << endl;
			// cout << ans << endl;
			cnt -= frek[index];
			frek[index] = 0;
			// cout << cnt << endl;
			pair<ll,ll> atas = pq.top();
			atas.cost *= -1;
			atas.ix *= -1;
			// cout << atas.cost << " " << atas.ix << endl;
			while (cnt)
			{
				// cout << atas.ix << " " << atas.cost << endl;
				ll tmp = min(cnt,frek[atas.ix]);
				// cout << tmp << endl;
				ans += tmp * atas.cost;
				frek[atas.ix] -= tmp;
				cnt -= tmp;
				if (frek[atas.ix] == 0)
					pq.pop();
				atas = pq.top();
				atas.cost *= -1;
				atas.ix *= -1;
			}
			cout << ans << endl;
		}
	}
}