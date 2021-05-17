#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
#define int long long
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a,b,m;
    cin >> a >> b >> m;
    if (a < b) swap(a,b);
    if (a >= m)
    {
        cout << 0 << endl;
        return 0;
    }
    if (a <= 0)
    {
        if (a >= m)
            cout << 0 << endl;
        else
            cout << -1 << endl;
    }
    else
    {
        ll ans = 0;
        const auto cei = [](int x,int y) -> int
        {
            return (x / y) + (x % y != 0);
        };
        if (b < 0) 
        {
            ans += cei(-b,a);
            b += cei(-b,a) * a;
        }
        while (a < m)
        {
            // cout << a << " " << b << endl;
            b += a;
            ++ans;
            if (a < b) swap(a,b);
        }
        cout << ans << endl;
    }
    return 0;
}