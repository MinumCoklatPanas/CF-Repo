// time-limit: 2000
// problem-url: https://codeforces.com/contest/1059/problem/A
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
    int n,k,a;
    cin >> n >> k >> a;
    int curTim = 0;
    int ans = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        int t,l;
        cin >> t >> l;
        int spare = t - curTim;
        ans += spare / a;
        curTim = t + l;
    }
    int rem = k - curTim;
    ans += rem / a;
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