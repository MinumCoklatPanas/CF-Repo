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
ll pref[100010];

ll getSum(ll l,ll r)
{
    if (l > r) return 0;
    return pref[r] - pref[l - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,l,r,ql,qr;
    cin >> n >> l >> r >> ql >> qr;
    for (ll i = 1 ; i <= n ; i++)
    {
        cin >> tab[i];
        pref[i] = tab[i] + pref[i - 1];
    }
    ll ans = INFF;
    for (ll i = 0 ; i <= n ; i++)
    {
        ll ki = i;
        ll ka = n - i;
        // cout << ki << " " << ka << " ";
        if (ki > ka)
        {
            ll rem = ki - ka;
            ll tot = getSum(1,ki) * l + getSum(ki + 1,n) * r;
            if (rem != 0)
                tot += (rem - 1) * ql;
            ans = min(ans,tot);
            // cout << tot << endl;
        }
        else
        {
            ll rem = ka - ki;
            ll tot = getSum(1,ki) * l + getSum(ki + 1,n) * r;
            // cout << tot << endl;
            if (rem != 0)
                tot += (rem - 1) * qr;
            ans = min(ans,tot);
            // cout << tot << endl;
        }
    }
    cout << ans << endl;
    return 0;
}