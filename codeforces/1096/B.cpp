#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 998244353;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	ll n;
	cin >> n;
	cin >> s;
	ll depan = 0;
	char kiri = s[0];
	char kanan = s.back();
	for (ll i = 0 ; i < s.length() ; i++)
	{
		if (s[i] != s[0]) break;
		++depan;
	}
	ll blkg = 0;
	reverse(s.begin(),s.end());
	for (ll i = 0 ; i < s.length() ; i++)
	{
		if (s[i] != s[0]) break;
		++blkg;
	}
	ll ans = depan + blkg + 1;
	ans %= MOD;
	// cout << ans << endl;
	if (kiri == kanan)
		ans += ((depan % MOD) * (blkg % MOD)) % MOD;
	ans %= MOD;
	cout << ans << endl;
}