#include <bits/stdc++.h>
using namespace std;
 
//Made with <3 by MinumCoklatPanas
typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 998244353;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

ll add(ll x,ll y)
{
	return ((x % MOD) + (y % MOD)) % MOD;
}

ll mul(ll x,ll y)
{
	return ((x % MOD) * (y % MOD)) % MOD;
}

ll pos[200010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,k;
	cin >> n >> k;
	for (ll i = 1 ; i <= n ; i++)
	{
		ll ta;
		cin >> ta;
		pos[ta] = i;
	}
	ll sum = 0;
	vector< ll > tmp;
	for (ll i = n ; i > n - k ; i--)
	{
		// sum = add(sum,i);
		sum += i;
		tmp.push_back(pos[i]);
	}
	sort(tmp.begin(),tmp.end());
	ll tot = 1;
	for (ll i = 1 ; i < tmp.size() ; i++)
	{
		tot = mul(tot,tmp[i] - tmp[i - 1]);
	}
	cout << sum << " " << tot << endl;
	return 0;
}