#include <bits/stdc++.h>
using namespace std;
 
//Made with <3 by MinumCoklatPanas
typedef long long ll;
const ll INF = 5e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

ll getCeil(vector<ll> &tmp,ll k)
{
	ll ix = lower_bound(tmp.begin(),tmp.end(),k) - tmp.begin();
	// cout << ix << " ix\n";
	// cout << "============================\n";
	if (ix >= tmp.size()) return INF;
	return tmp[ix];
}

ll getFloor(vector<ll> &tmp,ll k)
{
	ll ix = upper_bound(tmp.begin(),tmp.end(),k) - tmp.begin() - 1;
	if (ix < 0) return INF;
	return tmp[ix];
}

ll f(ll x,ll y,ll z)
{
	ll a = (x - y) * (x - y);
	ll b = (y - z) * (y - z);
	ll c = (z - x) * (z - x);
	return a + b + c;
}

ll getAns(vector< vector<ll> > &tab,ll curPos,ll x,ll y,ll z)
{
	ll ret = INF;
	if (curPos == 2)
	{
		// cout << x << " " << y << " " << z << endl;
		if (z != INF && y != INF)
			return f(x,y,z);
		else
			return INF;
	}
	else
	if (curPos == 1)
	{
		ll kanan = getCeil(tab[2],y);
		// cout << y << ": " << kanan << endl;
		ret = min(ret,getAns(tab,2,x,y,kanan));
		ll kiri = getFloor(tab[2],y);
		ret = min(ret,getAns(tab,2,x,y,kiri));
		return ret;
	}
	else
	{
		ll kanan = getCeil(tab[1],x);
		// cout << kanan << endl;
		ret = min(ret,getAns(tab,1,x,kanan,z));
		ll kiri = getFloor(tab[1],x);
		// cout << kiri << " kiri " << x << endl;
		ret = min(ret,getAns(tab,1,x,kiri,z));
		return ret;
	}
}

ll find(vector< vector<ll> > &tab)
{
	ll ret = INF;
	for (ll i = 0 ; i < tab[0].size() ; i++)
	{
		ll tmp = getAns(tab,0,tab[0][i],INF,INF);
		ret = min(ret,tmp);
		// cout << tmp << endl;
		// break;
	}
	return ret;
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
		ll r,g,b;
		cin >> r >> g >> b;
		vector< vector<ll> > vals;
		vector<ll> tmp;
		tmp.clear();
		for (ll i = 1 ; i <= r  ; i++)
		{
			ll ta;
			cin >> ta;
			tmp.push_back(ta);
		}
		sort(tmp.begin(),tmp.end());
		vals.push_back(tmp);
		tmp.clear();
		for (ll i = 1 ; i <= g  ; i++)
		{
			ll ta;
			cin >> ta;
			tmp.push_back(ta);
		}
		sort(tmp.begin(),tmp.end());
		vals.push_back(tmp);
		tmp.clear();
		for (ll i = 1 ; i <= b  ; i++)
		{
			ll ta;
			cin >> ta;
			tmp.push_back(ta);
		}
		sort(tmp.begin(),tmp.end());
		vals.push_back(tmp);
		vector<ll> perm = {0,1,2};
		ll ans = INF;
		do {
			vector< vector<ll> > tab = {vals[perm[0]],vals[perm[1]],vals[perm[2]]};
			ans = min(ans,find(tab));
			// break;
		} while (next_permutation(perm.begin(),perm.end()));
		cout << ans << endl;
	}
	return 0;
}