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

ll tab[100010];
ll frek[100010];
ll pref[100010];
map<ll,ll> mp;

ll get(ll l,ll r)
{
    if (l > r) return 0;
    return pref[r] - pref[l - 1];
}

ll cei(ll x,ll y)
{
    return ((x / y) + (x % y != 0));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,x,k;
    cin >> n >> x >> k;
    vector<ll> compress;
    for (ll i = 1 ; i <= n ; i++)
    {
        cin >> tab[i];
        compress.push_back(tab[i]);
    }
    sort(compress.begin(),compress.end());
    compress.erase(unique(compress.begin(),compress.end()),compress.end());
    ll ix = 1;
    for (auto it : compress)
    {
        mp[it] = ix++;
    }
    for (ll i = 1 ; i <= n ; i++)
    {
        frek[mp[tab[i]]]++;
    }
    for (ll i = 1 ; i <= n ; i++)
        pref[i] = pref[i - 1] + frek[i];
    ll ans = 0;
    for (auto it : compress)
    {
        ll cur = it;
        if (k == 0 && it % x == 0) continue;
        // if (k == 0)
        //     ans += frek[mp[it]] * frek[mp[it]];
        ll tmp = cei(it,x) * x + (k - 1) * x;
        ll nearest = max(tmp,it);
        ll furthest = tmp + x - 1;
        // cout << it << " " << nearest << " " << furthest << " " << tmp << endl;
        if (nearest > furthest) continue;
        ll l = lower_bound(compress.begin(),compress.end(),nearest) - compress.begin() + 1;
        ll r = upper_bound(compress.begin(),compress.end(),furthest) - compress.begin();
        ans += frek[mp[it]] * get(l,r);
    }
    cout << ans << endl;
    return 0;
}
