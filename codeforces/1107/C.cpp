#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAXN = 200000;

ll tab[MAXN + 10];
ll pref[MAXN + 10];
ll n,k;

ll sum(ll L,ll R)
{
	return pref[R] - pref[L - 1];
}

ll process(ll L,ll R)
{
	ll res = sum(L,R);
	priority_queue< ll > pq;
	for (ll i = L ; i <= R ; i++)
		pq.push(-tab[i]);
	while (pq.size() > k)
	{
		res += pq.top();
		pq.pop();
	}
	return res;
}

int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> tab[i];
		pref[i] = tab[i] + pref[i - 1];
	}
	string s;
	cin >> s;
	int i = 0;
	ll ans = 0ll;
	while (i < n)
	{
		char now = s[i];
		ll L = i;
		ll R;
		while (s[i] == now && i < n)
		{
			R = i;
			++i;
		} 
		// cout << L << " " << R << endl;
		ans += process(L + 1,R + 1);
	}
	cout << ans << endl;
}