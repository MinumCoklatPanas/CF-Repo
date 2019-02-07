#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 1e5;
const int MOD = 1e9 + 7;

ll dig(ll x)
{
	ll res = 0;
	while (x)
	{
		++res;
		x /= 2;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// for (int i = 2 ; i <= 1000 ; i++)
	// {
	// 	int mx = 0;
	// 	for (int j = 1 ; j < i ; j++)
	// 		mx = max(mx,__gcd(i ^ j,i & j));
	// 	cout << i << " " << mx << endl;
	// }
	int q;
	cin >> q;
	while (q--)
	{
		ll i;
		cin >> i;
		if (__builtin_popcountll(i + 1) == 1)
		{
			ll ans = 1ll;
			for (ll j = 2 ; j * j <= i ; j++)
			{
				if (i % j == 0)
				{
					ans = i / j;
					break;
				}
			}
			cout << ans << endl;
		}
		else
		{
			ll digit = dig(i);
			// cout << digit << endl;
			ll ans = (1ll << digit) - 1;
			cout << ans << endl;
		}
	}
}