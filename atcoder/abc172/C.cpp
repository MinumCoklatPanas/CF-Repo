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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> a(n),b(m);
    for (ll i = 0 ; i < n ; i++)
    {
        cin >> a[i];
        if (i > 0)
            a[i] += a[i - 1];
    }
    for (ll i = 0 ; i < m ; i++)
    {
        cin >> b[i];
        if (i > 0)
            b[i] += b[i - 1];
    }
    ll ans = 0;
    for (ll i = 0 ; i < n ; i++)
    {
        if (a[i] > k) break;
        ll ambil = i + 1;
        ll sisa = k - a[i];
        ll nxt = upper_bound(b.begin(),b.end(),sisa) - b.begin();
        ambil += nxt;
        ans = max(ans,ambil);
    }
    for (ll i = 0 ; i < m ; i++)
    {
        if (b[i] > k) break;
        ll ambil = i + 1;
        ll sisa = k - b[i];
        ll nxt = upper_bound(a.begin(),a.end(),sisa) - a.begin();
        ambil += nxt;
        ans = max(ans,ambil);
    }
    cout << ans << endl;
    return 0;
}