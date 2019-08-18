#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue< ll > pq;
	ll n;
	cin >> n;
	ll ans = 0;
	for (ll i = 1 ; i <= n ; i++)
	{
		ll ta;
		cin >> ta;
		if (ta > 0)
		{
			ans += ta - 1;
		}
		else
			pq.push(ta);
	}
	if (pq.size() % 2 == 1)
	{
		ll now = pq.top();
		pq.pop();
		ans += 1 - now;
	}
	while (!pq.empty())
	{
		ll now = pq.top();
		pq.pop();
		ans += abs(-1 - now);
	}
	cout << ans << endl;
}