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

ll a[55];
ll b[55];
ll n;

void solve()
{
    cin >> n;
    ll minA = MOD;
    ll minB = MOD;
    for (ll i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        minA = min(minA,a[i]);
    }
    for (ll i = 1 ; i <= n ; i++)
    {
        cin >> b[i];
        minB = min(minB,b[i]);
    }
    ll ans = 0;
    for (ll i = 1 ; i <= n ; i++)
    {
        if (a[i] > minA && b[i] > minB)
        {
            ll mn = min(a[i] - minA,b[i] - minB);
            ans += mn;
            a[i] -= mn;
            b[i] -= mn;
        }
        ans += a[i] - minA;
        ans += b[i] - minB;
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