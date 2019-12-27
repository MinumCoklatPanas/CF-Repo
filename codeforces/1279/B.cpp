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
ll pref[100010];
ll mx[100010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	while (t--)
	{
		ll n,s;
		cin >> n >> s;
		for (ll i = 1 ; i <= n ; i++)
		{
			cin >> tab[i];
			pref[i] = pref[i - 1] + tab[i];
			if (pref[i] <= s)
				mx[i] = i;
			else
				mx[i] = mx[i - 1];
		}
		if (pref[n] <= s)
			cout << 0 << endl;
		else
		{
			ll cnt = 0;
			ll ret = 0;
			for (ll i = 1 ; i <= n ; i++)
			{
				if (pref[i - 1] > s)
				{
					if (mx[i - 1] > cnt)
					{
						// cout << "yo\n";
						cnt = mx[i - 1];
						ret = i;
					}
				}
				else
				{
					// cout << "yo\n";
					// cout << i << endl;
					ll tmp = i - 1;
					if (i < n)
					{
						ll kurang = s - pref[i - 1];
						ll l = i + 1;
						ll r = n;
						while (r - l > 1)
						{
							ll mid = (l + r) >> 1;
							ll sum = pref[mid] - pref[i];
							if (sum <= kurang)
								l = mid;
							else
								r = mid - 1;
						}
						if (pref[r] - pref[i] <= kurang)
							tmp += r - i;
						else
						if (pref[l] - pref[i] <= kurang)
							tmp += l - i;
						// cout << tmp << endl;
					}
					if (tmp > cnt)
					{
						cnt = tmp;
						ret = i;
					}
				}
			}
			cout << ret << endl;
		}
	}
}