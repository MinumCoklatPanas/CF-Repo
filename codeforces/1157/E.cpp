#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;

ll a[200010];
multiset<ll> b;
ll c[200010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	for (ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	for (ll i = 1 ; i <= n ; i++)
	{
		ll ta;
		cin >> ta;
		b.insert(ta);
	}
	for (ll i = 1 ; i <= n ; i++)
	{
		ll now = a[i];
		ll butuh = n - a[i];
		ll satu = now + *(b.begin());
		satu %= n;
		multiset<ll>::iterator it = b.lower_bound(butuh);
		ll dua = INF;
		if (it != b.end())
		{
			dua = now + *it;
			dua %= n;
		}
		if (dua < satu)
			b.erase(it);
		else
			b.erase(b.begin());
		cout << min(dua,satu) << " ";
	}
	cout << endl;
}