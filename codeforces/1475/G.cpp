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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

set<int> pos[200010];
int dp[200010];
int tab[200010];
int frek[200010];

// int rec(int cur)
// {
//     if (dp[cur] != -1) return dp[cur];
//     // pos[tab[cur]].erase(pos[tab[cur]].find(cur));
//     int ret = 1;
//     for (int i = tab[cur] ; i <= 200000 ; i += tab[cur])
//     {
//         for 
//     }
//     cout << cur << " " << ret << endl;
//     return dp[cur] = ret;
// }

void solve()
{
    for (int i = 1 ; i <= 200000 ; i++)
    {
        pos[i].clear();
        dp[i] = 1;
        frek[i] = 0;
    }
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        tab[i] = ta;
        frek[ta]++;
    }
    for (int i = 1 ; i <= 200000 ; i++) dp[i] = frek[i];
    for (int i = 1 ; i <= 200000 ; i++) if (frek[i])
    {
        for (int j = i + i ; j <= 200000 ; j += i) if (frek[j])
        {
            dp[j] = max(dp[j],dp[i] + frek[j]);
        }
    }
    int mx = 0;
    for (int i = 1 ; i <= 200000 ; i++) mx = max(mx,dp[i]);
    // for (int i = 1 ; i <= 200000 ; i++) if (frek[i])
    //     cerr << i << " " << dp[i] << endl;
    // cout << mx << endl;
    cout << n - mx << endl;
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