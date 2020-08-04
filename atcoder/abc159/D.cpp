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

ll frek[200010];
ll tab[200010];

ll cnt(ll x)
{
    return (x * (x - 1)) / 2;
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
        cin >> tab[i];
        frek[tab[i]]++;
    }
    ll tot = 0;
    for (ll i = 1 ; i <= n ; i++)
    {
        tot += cnt(frek[i]);
    }
    // cout << tot << endl;
    for (ll i = 1 ; i <= n ; i++)
    {
        ll oldVal = cnt(frek[tab[i]]);
        ll newVal = cnt(frek[tab[i]] - 1);
        ll tmp = tot;
        ll delta = newVal - oldVal;
        // cout << i << ": " << delta << endl;
        cout << tot + delta << endl;
    }
    return 0;
}