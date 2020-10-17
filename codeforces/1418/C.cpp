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

int dp[200010][2];
int tab[200010];
int n;

int rec(int index,int player)
{
    if (index > n) return 0;
    if (dp[index][player] != -1) return dp[index][player];
    int ret = INF;
    if (player)
    {
        ret = min(rec(index + 1,0),rec(index + 2,0));
    }
    else
    {
        ret = min(ret,tab[index] + rec(index + 1,1));
        if (index + 1 <= n)
            ret = min(ret,tab[index] + tab[index + 1] + rec(index + 2,1));
    }
    // cout << index << " " << player << " " << ret << endl;
    return dp[index][player] = ret;
}

void solve()
{
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> tab[i];
        dp[i][0] = dp[i][1] = -1;
    }
    int ans = rec(1,0);
    cout << ans << endl;
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