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
	ll n,l,r;
	cin >> n >> l >> r;
	ll mn = ((1ll << l) - 1) + ((n - l));
	ll mx = ((1ll << r) - 1) + ((1ll << (r - 1)) * (n - r));
	cout << mn << " " << mx << endl;
}