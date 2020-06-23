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
ll n,m;
ll mn = INF;

ll calc1()
{
    ll i = 1;
    ll ans = 0;
    while (i + 1 + mn <= n)
    {
        i += 2;
        for (ll j = 0 ; j < mn ; j++)
        {
            if (i + j > n) break;
            ans += tab[i + j];
        }
        i += mn;
    }
    int rem = n - i + 1;
    if (rem > mn)
        ++i;
    while (i <= n)
    {
        ans += tab[i];
        ++i;
    }
    return ans;
}

ll calc2()
{
    ll i = 1;
    ll ans = 0;
    while (i + 1 + mn <= n)
    {
        for (ll j = 0 ; j < mn ; j++)
        {
            if (i + j > n) break;
            ans += tab[i + j];
        }
        i += 2;
        i += mn;
    }
    int rem = n - i + 1;
    if (rem > mn)
        --n;
    while (i <= n)
    {
        ans += tab[i];
        ++i;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m;
    for (ll i = 1 ; i <= m ; i++)
    {
        ll ta;
        cin >> ta;
        mn = min(mn,ta);
    }
    cin >> n;
    for (ll i = 1 ; i <= n ; i++)
        cin >> tab[i];
    sort(tab + 1,tab + n + 1);
    ll ans = calc1();
    // cout << "-----------------------------------------\n";
    reverse(tab + 1,tab + n + 1);
    ans = min(ans,calc2());
    cout << ans << endl;
    return 0;
}