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

void process(ll x,ll k,ll d)
{
    if (k % 2 == 0)
        cout << abs(x) << endl;
    else
    {
        ll ret = min(abs(x - d),abs(x + d));
        cout << ret << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll x,k,d;
    cin >> x >> k >> d;
    if (x == 0)
    {
        if (k % 2 == 0)
            cout << 0 << endl;
        else
            cout << d << endl;
    }
    else
    if (x < 0)
    {
        ll mx = -x / d;
        if (mx >= k)
        {
            ll ans = x + k * d;
            cout << abs(ans) << endl;
        }
        else
        {
            k -= mx;
            x += mx * d;
            ll nxt = x + d;
            if (abs(nxt) < abs(x))
                process(nxt,k - 1,d);
            else
                process(x,k,d);
        }
    }
    else
    {
        ll mx = x / d;
        // cout << mx << endl;
        if (mx >= k)
        {
            ll ans = x - k * d;
            cout << ans << endl;
        }
        else
        {
            k -= mx;
            x -= mx * d;
            ll nxt = x - d;
            if (abs(nxt) < abs(x))
                process(nxt,k - 1,d);
            else
                process(x,k,d);
        }
    }
    return 0;
}