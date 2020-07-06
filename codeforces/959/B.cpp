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

map<string,ll> mp;
string tab[100010];
ll val[100010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,k,m;
    cin >> n >> k >> m;
    for (ll i = 1 ; i <= n ; i++)
    {
        cin >> tab[i];
    }
    for (ll i = 1 ; i <= n ; i++)
        cin >> val[i];
    for (ll i = 1 ; i <= k ; i++)
    {
        ll c;
        cin >> c;
        vector<ll> ix;
        ll mn = INF;
        for (ll i = 1 ; i <= c ; i++)
        {
            ll ta;
            cin >> ta;
            ix.push_back(ta);
            mn = min(mn,val[ta]);
        }
        for (auto it : ix)
            mp[tab[it]] = mn;
    }
    ll ans = 0;
    for (ll i = 1 ; i <= m ; i++)
    {
        string ta;
        cin >> ta;
        ans += mp[ta];
    }
    cout << ans << endl;
    return 0;
}