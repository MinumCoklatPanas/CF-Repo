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

ll a[200010];
ll b[200010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	for (ll i = 1 ; i <= n ; i++)
		cin >> b[i];
	ll curMax = b[1];
	a[1] = curMax;
	for (ll i = 2 ; i <= n ; i++)
	{
		a[i] = b[i] + curMax;
		curMax = max(a[i],curMax);
	}
	for (ll i = 1 ; i <= n ; i++)
	{
		if (i == n)
			cout << a[i] << endl;
		else
			cout << a[i] << " ";
	}
	return 0;
}