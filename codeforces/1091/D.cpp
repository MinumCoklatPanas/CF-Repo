#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 998244353;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

ll add(ll x,ll y) {
	return ((x % MOD) + (y % MOD)) % MOD;
}

ll mul(ll x,ll y) {
	return ((x % MOD) * (y % MOD)) % MOD;
}

ll sub(ll x,ll y) {
	ll ret = ((x % MOD) - (y % MOD)) % MOD;
	if (ret < 0)
		ret += MOD;
	return ret;
}

ll dp[1000010];
ll fak[1000010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	dp[1] = 0;
	fak[1] = 1;
	for (int i = 2 ; i <= 1000000 ; i++) {
		fak[i] = mul(fak[i - 1],i);
		dp[i] = mul(i,dp[i - 1]);
		dp[i] = add(dp[i],mul(i - 1,i - 1));
	} 
	ll n;
	cin >> n;
	ll ans = mul(n,fak[n]);
	ans = sub(ans,n - 1);
	ans = sub(ans,dp[n]);
	cout << ans << endl;
}