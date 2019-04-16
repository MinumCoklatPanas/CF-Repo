#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 2e5;
const ll MOD = 1e9 + 7;

ll tab[14] = {1,2,3,1,3,2,1,1,2,3,1,3,2,1};
ll a,b,c;

ll coba(ll x)
{
	ll tmpA = a,tmpB = b,tmpC = c;
	for (ll i = x ; i < 14 ; i++)
	{
		if (tab[i] == 1 && tmpA == 0) return i - x ;
		if (tab[i] == 2 && tmpB == 0) return i - x ;
		if (tab[i] == 3 && tmpC == 0) return i - x ;
		if (tab[i] == 1) --tmpA;
		if (tab[i] == 2) --tmpB;
		if (tab[i] == 3) --tmpC;
	}
	// assert(false);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b >> c;
	ll mxA = a / 3;
	ll mxB = b / 2;
	ll mxC = c / 2;
	ll tahan = min(mxA,min(mxB,mxC));
	a -= tahan * 3;
	b -= tahan * 2;
	c -= tahan * 2;
	ll ans = 7 * tahan;
	ll mx = 0;
	for (ll i = 0 ; i < 7 ; i++)
	{
		// cout << i << " " << coba(i) << endl;
		mx = max(mx,coba(i));
	}
	ans += mx;
	cout << ans << endl;
}