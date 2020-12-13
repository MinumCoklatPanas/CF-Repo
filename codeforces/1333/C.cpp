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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int long long

map<ll,int> mp;
ll tab[200010];
ll pref[200010];
ll BIT[200010];
ll n;

void upd(int x,int val)
{
    for ( ; x <= n ; x += (x & -x))
        BIT[x] = max(BIT[x],val);
}

int query(int x)
{
    int ret = -1;
    for ( ; x ; x -= (x & -x))
        ret = max(ret,BIT[x]);
    return ret;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ll sum = 0;
    ll cnt = 0;
    mp[0] = 0;
    for (ll i = 1 ; i <= n ; i++)
    {
        cin >> tab[i];
        sum += tab[i];
        pref[i] = sum;
    }
    memset(BIT,-1,sizeof(BIT));
    for (int i = 1 ; i <= n ; i++)
    {
        if (mp.count(pref[i]))
        {
            upd(mp[pref[i]] + 1,mp[pref[i]] + 1);
        }
        int mx = query(i);
        if (mx != -1)
        {
            cnt += mx;
        }
        mp[pref[i]] = i;
    }
    ll ans = (n * (n + 1)) / 2;
    ans -= cnt;
    cout << ans << endl;
    return 0;
}