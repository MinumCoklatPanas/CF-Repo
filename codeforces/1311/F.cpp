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

struct data
{
	ll pos;
	ll v;

	bool operator < (data &other) const 
	{
		if (v == other.v)
			return pos < other.pos;
		else
			return v < other.v;
	}
};

ll BIT[4][200010];
map<ll,ll> mp;
map<ll,ll> balik;
vector< ll > compress;
data tab[200010];

void upd(ll kode,ll x,ll val)
{
	for ( ; x <= 200000 ; x += (x & -x))
		BIT[kode][x] += val;
}

ll query(ll kode,ll x)
{
	ll ret = 0;
	for ( ; x ; x -= (x & -x))
		ret += BIT[kode][x];
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	for (ll i = 1 ; i <= n ; i++)
	{
		cin >> tab[i].pos;
		compress.push_back(tab[i].pos);
	}
	sort(compress.begin(),compress.end());
	compress.erase(unique(compress.begin(),compress.end()),compress.end());
	for (ll i = 0 ; i < compress.size() ; i++)
	{
		mp[compress[i]] = i + 1;
		balik[i + 1] = compress[i];
	}
	for (ll i = 1 ; i <= n ; i++)
	{
		cin >> tab[i].v;
	}
	sort(tab + 1,tab + n + 1);
	// for (ll i = 1 ; i <= n ; i++)
	// 	cout << "(" << mp[tab[i].pos] << "," << tab[i].v << ")\n"; 
	for (ll i = 1 ; i <= n ; i++)
	{
		upd(1,mp[tab[i].pos],tab[i].pos);
		upd(3,mp[tab[i].pos],1);
	}
	// return 0;
	ll ans = 0;
	for (ll i = 1 ; i <= n ; i++)
	{
		upd(1,mp[tab[i].pos],-tab[i].pos);
		upd(3,mp[tab[i].pos],-1);
		ll ret = 0;
		ll sum_kiri = query(0,mp[tab[i].pos] - 1);
		ll cnt_kiri = query(2,mp[tab[i].pos] - 1);
		// cout << sum_kiri << " " << cnt_kiri << endl;
		ret += (tab[i].pos * cnt_kiri) - sum_kiri;
		// ll sum_kanan = query(1,200000) - query(1,mp[tab[i].pos]);
		// ll cnt_kanan = query(3,200000) - query(3,mp[tab[i].pos]);
		// ret += sum_kanan - (tab[i].pos * cnt_kanan);
		upd(0,mp[tab[i].pos],tab[i].pos);
		upd(2,mp[tab[i].pos],1);
		// cout << (tab[i].pos * cnt_kiri) - sum_kiri << " " << sum_kanan - (tab[i].pos * cnt_kanan) << endl;
		ans += ret;
	}
	cout << ans << endl;
	return 0;
}