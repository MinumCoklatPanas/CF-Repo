#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;

pair<ll,ll> tab[300010];
ll dp[3][300010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll q;
	cin >> q;
	while (q--)
	{	
		ll n;
		cin >> n;
		for (ll i = 1 ; i <= n ; i++)
		{
			cin >> tab[i].first >> tab[i].second;
			dp[0][i] = 0;
			dp[1][i] = tab[i].second;
			dp[2][i] = tab[i].second * 2;
		}
		for (ll i = 1 ; i <= n ; i++)
		{
			for (ll j = 0 ; j < 3 ; j++)
			{
				ll mn = INFF;
				ll change = tab[i].first + j;
				for (ll k = 0 ; k < 3 ; k++)
				{
					if (change != tab[i - 1].first + k)
						mn = min(mn,dp[k][i - 1]);
				}
				if (mn == INFF)
					dp[j][i] = INFF;
				else
					dp[j][i] += mn;
			}
		}
		ll ans = min(dp[0][n],min(dp[1][n],dp[2][n]));
		cout << ans << endl;
	}
}