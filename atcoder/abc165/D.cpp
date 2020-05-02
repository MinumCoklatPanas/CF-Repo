#include <bits/stdc++.h>
using namespace std;
 
//Made with <3 by MinumCoklatPanas
typedef unsigned long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll a,b,n;
	cin >> a >> b >> n;
	// assert(a != b);
	ll mx = (n / b) * b;
	if (mx == n && n != 1)
		--mx;
	else
		mx = n;
	mx = max(mx,1ull);
	// cout << mx << endbl;
	ll ans = ((mx * a) / b) - (a * (mx / b));
	ll mn = min(n,b - 1);
	ll tmp = ((mn * a) / b) - (a * (mn / b));
	ans = max(ans,tmp);
	cout << max(ans,0ull) << endl;
	return 0;
}