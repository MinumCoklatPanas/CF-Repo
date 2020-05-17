#include <bits/stdc++.h>
using namespace std;
 
//Made with <3 by MinumCoklatPanas
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

ll cei(ll x,ll y)
{
	return ((x / y) + (x % y != 0));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		ll n,k;
		cin >> n >> k;
		ll loncat = n - 1;
		ll blok = cei(k,loncat);
		ll sisa = k - ((blok - 1) * loncat);
		ll ans = (blok - 1) * n + sisa;
		cout << ans << endl;
	}
	return 0;
}