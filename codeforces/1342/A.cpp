#include <bits/stdc++.h>
using namespace std;
 
//Made with <3 by MinumCoklatPanas
typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	while (t--)
	{
		ll x,y;
		cin >> x >> y;
		ll a,b;
		cin >> a >> b;
		if (y < x)
			swap(x,y);
		ll ans = (y - x) * a + min(x * b,(x + x) * a);
		cout << ans << endl;
	}
	return 0;
}