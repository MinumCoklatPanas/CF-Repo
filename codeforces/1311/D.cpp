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

ll flo(ll x,ll y)
{
	return (x / y);
}

ll cei(ll x,ll y)
{
	return (x / y) + (x % y != 0);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	while (t--)
	{
		ll a,b,c;
		cin >> a >> b >> c;
		ll mn = INFF;
		ll A = -1, B = -1, C = -1;
		for (ll i = 1 ; i <= 15000 ; i++)
		{
			ll atas_floor = flo(c,i) * i;
			ll atas_ceil = (flo(c,i) + 1) * i;
			ll atas,bawah;
			ll sum = abs(i - b);
			if (abs(atas_floor - c) < abs(atas_ceil - c))
				atas = atas_floor;
			else
				atas = atas_ceil;
			sum += abs(atas - c);
			bawah = INFF;
			for (ll j = 1 ; j * j <= i ; j++) if (i % j == 0)
			{
				ll smol = j;
				ll big = i / j;
				if (abs(smol - a) < abs(bawah - a))
					bawah = smol;
				if (abs(big - a) < abs(bawah - a))
					bawah = big;
			}
			assert(bawah != INFF);
			sum += abs(bawah - a);
			if (sum < mn)
			{
				mn = sum;
				A = bawah;
				B = i;
				C = atas;
			}
		}
		cout << mn << endl;
		cout << A << " " << B << " " << C << endl;
	}
	return 0;
}