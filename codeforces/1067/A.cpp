#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
// #define int long long
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 998244353;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int tab[100010];
int dp[100010][210][2];
int n;

int add(int x,int y)
{
    return ((x % MOD) + (y % MOD)) % MOD;
}

int sub(int x,int y)
{
    int ret = ((x % MOD) - (y % MOD)) % MOD;
    if (ret < 0) ret += MOD;
    return ret;
}

signed main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    // cin >> n;
    scanf("%d",&n);
    for (int i = 1 ; i <= n ; i++)
    {
        scanf("%d",&tab[i]);
    }
    const auto process = [](int ix) -> void
    {
        for (int i = 1 ; i <= 200 ; i++)
        {
            dp[ix][i][0] = add(dp[ix][i][0],dp[ix][i - 1][0]);
            dp[ix][i][1] = add(dp[ix][i][1],dp[ix][i - 1][1]);
        }
    };
    const auto get = [](int ix,int l,int r,int flag) -> int
    {
        if (l > r) return 0;
        return sub(dp[ix][r][flag],dp[ix][l - 1][flag]);
    };
    if (tab[1] == -1)
    {
        for (int i = 1 ; i <= 200 ; i++) dp[1][i][1] = 1;
    }
    else
        dp[1][tab[1]][1] = 1;
    process(1);
    for (int i = 2 ; i < n ; i++)
    {
        if (tab[i] == -1)
        {
            for (int j = 1 ; j <= 200 ; j++)
            {
                //naik
                dp[i][j][1] = add(get(i - 1,1,j - 1,0),get(i - 1,1,j - 1,1));
                //turun
                if (i == 2)
                    dp[i][j][0] = add(get(1,j,j,0),get(1,j,j,1));
                else
                    dp[i][j][0] = add(get(i - 1,j,200,0),get(i - 1,j,j,1));
                // if (j <= 3)
                //     cout << dp[i][j][1] << " " << dp[i][j][0] << endl;
            }
        }
        else
        {
            if (i == 2)
            {
                dp[i][tab[i]][0] = add(get(1,tab[i],tab[i],0),get(1,tab[i],tab[i],1));
                dp[i][tab[i]][1] = add(get(i - 1,1,tab[i] - 1,0),get(i - 1,1,tab[i] - 1,1));
            }
            else
            {
                dp[i][tab[i]][1] = add(get(i - 1,1,tab[i] - 1,0),get(i - 1,1,tab[i] - 1,1));
                dp[i][tab[i]][0] = add(get(i - 1,tab[i],200,0),get(i - 1,tab[i],tab[i],1));
            }
        }
        process(i);
    }
    // for (int i = 1 ; i <= n ; i++)
    // {
    //     cerr << i << endl;
    //     cerr << "=======================================\n";
    //     for (int j = 1 ; j <= 3 ; j++)
    //         cerr << get(i,j,j,0) << " " << get(i,j,j,1) << endl;
    //     cerr << "=======================================\n";
    // }
    int ans = 0;
    if (tab[n] == -1)
    {
        for (int i = 1 ; i <= 200 ; i++)
        {
            ans = add(ans,get(n - 1,i,200,0));
            ans = add(ans,get(n - 1,i,i,1));
        }
    }
    else
        ans = add(get(n - 1,tab[n],200,0),get(n - 1,tab[n],tab[n],1));
    printf("%d\n",ans);
    return 0;
}