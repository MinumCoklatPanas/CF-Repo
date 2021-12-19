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

char tab[110][110];
int dp[110][110];
int n,m;

int rec(int x,int y)
{
    if (x > n) return 0;
    if (x < 1) return 0;
    if (y > m) return 0;
    if (y < 1) return 0;
    if (tab[x][y] == '#') return 0;
    if (dp[x][y] != -1) return dp[x][y];
    int &ret = dp[x][y];
    ret = 1 + max(rec(x + 1,y),rec(x,y + 1));
    return ret;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= m ; j++)
        {
            cin >> tab[i][j];
            dp[i][j] = -1;
        }
    int ans = rec(1,1);
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