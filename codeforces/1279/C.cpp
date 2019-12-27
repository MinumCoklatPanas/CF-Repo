#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<ll, null_type, less<ll>,
rb_tree_tag,tree_order_statistics_node_update>
ordered_set;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

map<ll,ll> mp;
ll gift[100010];
ll urutan[100010];
ordered_set st;
ll n,m;


ll cari(ll ix,ll &last)
{
	ll cnt = 0;
	for (ll i = last ; i <= n ; i++)
	{
		if (gift[i] == ix)
		{
			// cout << i << " dapat " << st.size() << endl;
			last = i + 1;
			return cnt * 2 + 1;
		}
		else
		if (1)
		{
			// cout << i << " masuk\n";
			// cout << "yo\n"
			st.insert(gift[i]);
		}
		++cnt;
	}
	assert(false);
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
		st.clear();
		mp.clear();
		cin >> n >> m;
		for (ll i = 1 ; i <= n ; i++)
			cin >> gift[i];
		vector<ll> tipe;
		for (ll i = 1 ; i <= m ; i++)
		{
			ll ta;
			cin >> ta;
			urutan[i] = ta;
			tipe.push_back(ta);
		}
		// sort(tipe.begin(),tipe.end());
		for (ll i = 0 ; i < m ; i++)
			mp[tipe[i]] = i + 1;
		int cnt = 1;
		for (ll i = 1 ; i <= n ; i++)
		{
			if (!mp.count(gift[i]))
			{
				gift[i] = m + cnt;
				++cnt;
			}
			else
				gift[i] = mp[gift[i]];
			// cout << gift[i] << " ";
		}
		// cout << endl;
		ll ans = 0;
		ll last = 1;
		for (ll i = 1 ; i <= m ; i++)
		{
			ll ix = st.order_of_key(i);
			// cout << i << " " << st.size() << endl;
			if (*st.find_by_order(ix) != i) {
				ans += 2 * st.size();
				ans += cari(i,last);
			}
			else
			{
				// cout << "yo " << ix << endl;;
				st.erase(st.find_by_order(ix));
				ans += 2 * ix + 1;
			}
		}
		cout << ans << endl;
	}
}