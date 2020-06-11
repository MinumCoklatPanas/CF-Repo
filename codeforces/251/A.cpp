#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

ll cnt(ll l,ll r)
{
    // cout << l << " " << r << " " << ((r + l) * (r - l + 1)) / 2 << endl;
    return ((r + l) * (r - l + 1)) / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,d;
    cin >> n >> d;
    ll ans = (n * (n - 1) * (n - 2)) / 6;
    vector< ll > tab;
    for (int i = 1 ; i <= n ; i++)
    {
        ll ta;
        cin >> ta;
        tab.push_back(ta);
    }
    // cout << ans << endl;
    for (int i = 0 ; i < n ; i++)
    {
        ll ix = upper_bound(tab.begin(),tab.end(),tab[i] + d) - tab.begin();
        // cout << i << " " << ix << endl;
        if  (ix == n) continue;
        ll l = ix - i;
        ll r = n - 1 - i;
        ans -= cnt(l - 1,r - 1);
    }
    cout << ans << endl;
    return 0;
}