#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

ll tab[100010];

ll cnt(ll x)
{
	if (x == 0) return 1;
	ll ret = 0;
	while (x)
	{
		x /= 2;
		++ret;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	srand(time(NULL));
	// toBit(3);
	// cout << (1 + 12 + 23 + 5 + 95 + 32 + 32) << endl;
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		// n = 100000;
		ll sum = 0;
		ll sor = 0;
		for (ll i = 1 ; i <= n ; i++)
		{
			cin >> tab[i];
			// tab[i] = 1000000000;
			sum += tab[i];
			sor ^= tab[i];
		}
		if (sum == 2 * sor)
		{
			cout << 0 << endl;
			cout << endl;
			continue;
		}
		ll dig = cnt(sum);
		// cout << dig << endl;
		ll target = (1ll << (dig + 3));
		// cout << target << endl;
		// cout << sor << endl;
		ll fix = (target / 2) ^ sor;
		// cout << fix << endl;
		ll rem = target - (fix + sum);
		// assert(rem >= 0);
		cout << 3 << endl;
		cout << fix << " " << (rem / 2) << " " << (rem / 2) << endl;
		sum += fix + rem;
		sor ^= fix;
		assert(sum == 2 * sor);
	}
}	