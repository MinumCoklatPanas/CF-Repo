#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;

ll tab[2][100010];
ll DP[2][100010];
ll mx[2][100010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	for (ll i = 1 ; i <= n ; i++)
		cin >> tab[0][i];
	for (ll i = 1 ; i <= n ; i++)
		cin >> tab[1][i];
	DP[0][1] = tab[0][1];
	DP[1][1] = tab[1][1];
	for (ll i = 2 ; i <= n ; i++)
	{
		DP[0][i] = max(DP[0][i - 1],DP[1][i - 1] + tab[0][i]);
		DP[1][i] = max(DP[1][i - 1],DP[0][i - 1] + tab[1][i]);
	}
	ll ans = max(DP[0][n],DP[1][n]);
	cout << ans << endl;
}