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

vector<ll> pos[3010];
ll tab[3010];

void solve()
{
    ll n;
    cin >> n;
    for (ll i = 1 ; i <= n ; i++) pos[i].clear();
    for (ll i = 1 ; i <= n ; i++)
    {
        cin >> tab[i];
        pos[tab[i]].push_back(i);
    }
    ll ans = 0;
    for (ll i = 1 ; i <= n ; i++)
    {
        for (ll j = i + 1 ; j <= n ; j++)
        {
            if (pos[tab[j]][0] == j) continue;
            if (pos[tab[i]].back() == i) continue;
            ll kiri = lower_bound(pos[tab[j]].begin(),pos[tab[j]].end(),i) - pos[tab[j]].begin();
            ll kanan = pos[tab[i]].size() - (upper_bound(pos[tab[i]].begin(),pos[tab[i]].end(),j) - pos[tab[i]].begin());
            ans += kiri * kanan;
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}