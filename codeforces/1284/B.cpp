#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2")  //Enable AVX
#pragma GCC optimize("O2")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native,avx2")

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

ll mn[100010];
ll frekMin[1000010];
ll frekMax[1000010];
ll asu[1000010];
ll BIT[1000010];
ll pref[1000010];

inline int readInt ()
{
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (true)
    {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true;
    else result = ch-'0';
    while (true)
    {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

void upd(ll x)
{
	for ( ; x <= 1000000 ; x += (x & -x))
		BIT[x]++;
}

ll query(ll x)
{
	ll ret = 0;
	for ( ; x ; x -= (x & -x))
		ret += BIT[x];
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n = readInt();
	// cin >> n;
	ll ans = 0;
	vector< pair<ll,ll> > rem;
	ll kntl = 0;
	ll ajg = n;
	for (ll i = 1 ; i <= n ; i++)
	{
		ll k = readInt();
		// cin >> k;
		ll fi = readInt();
		// cin >> fi;
		ll tmp = fi;
		ll tmp2 = fi;
		ll bef = tmp;
		bool sama_semua = 1;
		bool valid = 0;
		for (ll j = 1 ; j < k ; j++)
		{
			ll ta = readInt();
			// cin >> ta;
			if (ta > bef)
				valid = 1;
			tmp = min(tmp,ta);
			tmp2 = max(tmp2,ta);
			bef = ta;
			if (ta != fi)
				sama_semua = false;
		}
		if (!sama_semua && k != 1)
		{
			// cout << i << endl;
			++ans;
		}
		if (valid)
		{
			// cout << i << endl;
			ans += 2 * ajg - 2;
			// ++kntl;
			--ajg;
		}
		else
		{
			// cout << "yo\n";
			// cout << tmp << " " << tmp2 << endl;
			rem.emplace_back(tmp,tmp2);
			frekMin[tmp]++;
			// cout << tmp << endl;
		}
		// cout << i << " " << ans << endl;
	}
	for (int i = 1 ; i <= 1000000 ; i++)
		frekMin[i] += frekMin[i - 1];
	// cout << ans << endl;
	sort(rem.begin(),rem.end());
	ll tot = 0;
	for (auto it : rem)
	{
		ll mx = it.second;
		ll mn = it.first;
		// cout << tot << " tot\n";
		// cout << mx << " " << query(mx) << endl;
		ans += frekMin[mx - 1] - (mx != mn);
		tot++;
	}
	printf("%lld\n", ans);
	// cout << ans << endl;
	return 0;
}