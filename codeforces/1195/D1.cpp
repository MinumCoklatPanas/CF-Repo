#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 998244353;

ll tab[100010];

ll add(ll x,ll y)
{
	return ((x % MOD) + (y % MOD)) % MOD;
}

ll mul(ll x,ll y)
{
	return ((x % MOD) * (y % MOD)) % MOD;
}

ll kali[25];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	kali[0] = 1;
	for (ll i = 1 ; i <= 23 ; i++)
		kali[i] = mul(kali[i - 1],10);
	ll n;
	cin >> n;
	for (ll i = 1 ; i <= n ; i++)
		cin >> tab[i];
	sort(tab + 1,tab + n + 1);
	ll ans = 0ll;
	for (ll i = 1 ; i <= n ; i++)
	{
		ll tmp = tab[i];
		//kalau lebih kecil
		ll smol = 0;
		ll urutan = 2;
		while (tmp)
		{
			smol = add(smol,mul(tmp % 10,kali[urutan - 1]));
			tmp /= 10;
			urutan += 2;
		}
		// if (i == 1)
		// 	cout << smol << endl;
		smol = mul(smol,n - 1);
		//kalau lebih besar
		tmp = tab[i];
		ll big = 0;
		urutan = 1;
		while (tmp)
		{
			big = add(big,mul(tmp % 10,kali[urutan - 1]));
			tmp /= 10;
			urutan += 2;
		}
		big = mul(big,n - 1);
		//kalau sama
		tmp = tab[i];
	 	urutan = 1;
		ll sama = 0;
		while (tmp)
		{
			sama = add(sama,mul(tmp % 10,kali[urutan - 1]));
			++urutan;
			sama = add(sama,mul(tmp % 10,kali[urutan - 1]));
			++urutan;
			tmp /= 10;
		}
		ans = add(ans,smol);
		ans = add(ans,big);
		ans = add(ans,sama);
	}
	cout << ans << endl;
}