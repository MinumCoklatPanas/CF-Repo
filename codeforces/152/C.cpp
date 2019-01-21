#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll mul(ll x,ll y)
{
	return ((x % MOD) * (y % MOD)) % MOD;
}

char tab[110][110];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin >> n >> m;
	for (ll i = 1 ; i <= n ; i++)
		for (ll j = 1 ; j <= m ; j++)
			cin >> tab[i][j];
	ll ans = 1;
	for (ll i = 1 ; i <= m ; i++)
	{
		set<char> st;
		for (ll j = 1 ; j <= n ; j++)
			st.insert(tab[j][i]);
		ans = mul(ans,(ll)st.size());
	}
	cout << ans << endl;
}