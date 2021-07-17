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
#define MULTI_TC 0

int getTC()
{
    if (MULTI_TC)
    {
        int t;
        cin >> t;
        return t;
    }
    else return 1;
}

void solve()
{
    int l,r,x,y;
    cin >> l >> r >> x >> y;
    int bound = y / x;
    int ans = 0;
    for (int i = 1 ; i * i <= bound ; i++) if (bound % i == 0)
    {
        int k = i;
        int c = bound / i;
        int a = k * x;
        int b = c * x;
        if (!((l <= a && a <= r) && (l <= b && b <= r))) continue;
        int gcd = __gcd(a,b);
        int lcm = a / gcd * b;
        if (gcd == x && lcm == y)
            ans += (a == b ? 1 : 2);
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = getTC();
    while (t--)
    {
        solve();
    }
    return 0;
}