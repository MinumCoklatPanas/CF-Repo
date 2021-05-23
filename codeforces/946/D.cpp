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

int dp[510][510];
int prec[510][510];
vector<int> pos[510];
int n,m,k;

int rec(int ix,int rem)
{
    if (ix > n) return 0;
    if (dp[ix][rem] != -1) return dp[ix][rem];
    int ret = INF;
    for (int i = 0 ; i <= rem ; i++)
    {
        ret = min(ret,prec[ix][i] + rec(ix + 1,rem - i));
    }
    return dp[ix][rem] = ret;
}

void solve()
{
    cin >> n >> m >> k;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= m ; j++)
        {
            char ta;
            cin >> ta;
            if (ta == '1') pos[i].push_back(j);
        }
    }
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 0 ; j <= min(k,(ll)pos[i].size()) ; j++)
        {
            int mn = INF;
            for (int depan = 0 ; depan <= j ; depan++)
            {
                int belakang = j - depan;
                if (depan == pos[i].size())
                {
                    mn = 0;
                    break;
                }
                int l = depan;
                int r = pos[i].size() - belakang - 1;
                mn = min(mn,pos[i][r] - pos[i][l] + 1);
            }
            // cout << i << " " << j << " " << mn << endl;
            prec[i][j] = mn;
        }
    }
    memset(dp,-1,sizeof(dp));
    int ans = rec(1,k);
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