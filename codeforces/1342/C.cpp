#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

ll findLo(ll l,ll a,ll c)
{
	ll lo = 0;
	ll hi = (l / a) + (l % a != 0);
	while (hi - lo > 1)
	{
		ll mid = (lo + hi) >> 1;
		if (l <= a * mid + c)
			hi = mid;
		else
			lo = mid + 1; 
	}
	if (l <= lo * a + c)
		return lo;
	else
		return hi;
}

ll findHi(ll r,ll a,ll c)
{
	ll lo = 0;
	ll hi = r / a;
	while (hi - lo > 1)
	{
		ll mid = (hi + lo) >> 1;
		if (r >= a * mid + c)
			lo = mid;
		else
			hi = mid - 1;
	}
	if (r >= a * hi + c)
		return hi;
	else
		return lo;
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);
	ll t;
	// cin >> t;
	scanf("%lld",&t);
	while (t--)
	{
		ll a,b,q;
		scanf("%lld %lld %lld",&a,&b,&q);
		// cin >> a >> b >> q;
		if (a > b)
			swap(a,b);
		while (q--)
		{	
			ll lcm = (a * b) / __gcd(a,b);
			ll l,r;
			scanf("%lld %lld",&l,&r);
			// cin >> l >> r;
			ll ans = r - l + 1;
			for (ll i = 0 ; i < b ; i++)
			{
				if (r < i) continue;
				// ll lo = findLo(l,b,i);
				// ll hi = findHi(r,b,i);
				// // cout << (r - i) / 4 << endl;
				// // cout << hi << " " << lo << endl;
				// ans -= hi - lo  + 1;
				if (1)
				{
					// ll lo = findLo(l,lcm,i);
					// ll hi = findHi(r,lcm,i);
					ll lo = ((l - i) / lcm) + ((l - i) % lcm != 0);
					if (l < i)
						lo = 0;
					ll hi = (r - i) / lcm;
					// cout << i << ": " << lo << " " << hi << endl;
					ans -= hi - lo + 1;
				}
			}
			printf("%lld ",ans);
			// cout << ans << " ";
		}
		puts("");
		// cout << endl;
	}
	return 0;
}