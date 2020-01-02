#include <bits/stdc++.h>
using namespace std;
 
//Made with <3 by MinumCoklatPanas
typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
const ll MAXN = 2e5 + 10;

ll tab[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	while (t--)
	{
		ll n,p,k;
		cin >> n >> p >> k;
		for (ll i = 1 ; i <= n ; i++)
		{
			cin >> tab[i];
		}
		sort(tab + 1,tab + n + 1);
		ll ans = 0;
		ll tot = 0;
		for (ll i = 1 ; i <= k ; i++)
		{
			if (tot > p) break;
			ll cnt = i - 1;
			ll tmp = tot;
			for (ll j = i + k - 1 ; j <= n ; j += k)
			{
				if (tmp + tab[j] <= p)
				{
					cnt += k;
					tmp += tab[j];
				}
				else
					break;
			}
			ans = max(ans,cnt);
			tot += tab[i];
		}
		cout << ans << endl;
	}
	return 0;
}