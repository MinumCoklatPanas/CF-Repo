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

void solve()
{
    ll x,y,p,q;
    cin >> x >> y >> p >> q;
    if (x * q == y * p)
    {
        cout << "0\n";
        return;
    }
    if (p == q || p == 0)
    {
        cout << -1 << endl;
        return;
    }
    ll a = (ll)ceil(double(x - y) / (double)(p - q));
    a = max(a,(ll)ceil((double) x / (double) p ));
    a = max(a,(ll)ceil((double) y / (double) q ));
    // cout << a << " a\n";
    ll atas = p * a - x;
    ll bawah = q * a - y;
    // cout << atas << " " << bawah << endl;
    cout << bawah << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}