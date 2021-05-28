// time-limit: 1000
// problem-url: https://codeforces.com/contest/1526/problem/B
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
#define MULTI_TC 1

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
vector<int> dp(1000010,0);
vector<int> hehe = {11,111,1111,11111,111111,1111111,11111111};

void solve()
{
    int x;
    cin >> x;
    if (x >= 1000000)
        cout << "YES\n";
    else
    {
        if (dp[x])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

void bf()
{
    dp[0] = 1;
    dp[11] = 1;
    for (int i = 12 ; i <= 1000000 ; i++)
    {
        for (auto it : hehe) if (i - it >= 0)
            dp[i] |= dp[i - it];
    }
    // for (int i = 11 ; i <= 5000 ; i++)
    // {
    //     cout << i << " " << dp[i] << endl;
    //     // if (i >= 1000 && !dp[i])
    //     //     cout << i << endl;
    // }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    bf();
    int t = getTC();
    while (t--)
    {
        solve();
    }
    return 0;
}