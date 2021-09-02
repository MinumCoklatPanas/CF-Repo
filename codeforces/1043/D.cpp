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
    int n,m;
    cin >> n >> m;
    vector<vector<int>> tab(m,vector<int>(n));
    for (auto &it : tab)
    {
        for (auto &it2 : it) cin >> it2;
    }
    vector<int> mp(n + 5);
    for (int i = 0 ; i < n ; i++)
    {
        mp[tab[0][i]] = i + 1;
    }
    for (auto &it : tab)
    {
        for (auto &it2 : it)
        {
            it2 = mp[it2];
        }
    }
    vector<vector<int>> dp(m,vector<int>(n + 5,1));
    for (int i = 0 ; i < m ; i++)
    {
        dp[i][tab[i][0]] = 1;
        for (int j = 1 ; j < n ; j++)
        {
            if (tab[i][j - 1] + 1 == tab[i][j])
                dp[i][tab[i][j]] = dp[i][tab[i][j - 1]] + 1;
            else
                dp[i][tab[i][j]] = 1;
        }
        // for (auto it : tab)
        // for (int j = 1 ; j <= n ; j++)
        //     cerr << dp[i][j] << " ";
        // cerr << endl;
    }
    vector<int> dpAll(n + 5,INF);
    int ans = 0;
    dpAll[0] = 0;
    const auto cnt = [](int x) -> int
    {
        return (x * (x + 1)) / 2;
    };
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 0 ; j < m ; j++)
        {
            dpAll[i] = min(dpAll[i],dp[j][i]);
        }
        if (dpAll[i] == 1)
        {
            ans += cnt(dpAll[i - 1]);
        }
    }
    ans += cnt(dpAll[n]);
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