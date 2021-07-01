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
    int n,a,b,p,q;
    cin >> n >> a >> b >> p >> q;
    int lcm = (a * b) / __gcd(a,b);
    const auto cnt = [&](int x,int y) -> int
    {
        return x / y;
    };
    int pastiMerah = cnt(n,a) - cnt(n,lcm);
    int pastiBiru = cnt(n,b) - cnt(n,lcm);
    int both = cnt(n,lcm);
    int ans = pastiMerah * p + pastiBiru * q + both * max(p,q);
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