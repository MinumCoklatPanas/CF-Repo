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

int n,m;
int tab[1010];
int cost[1010];
int dp[1010][5010]; //[indeks][mask]

int rec(int indeks,int mask)
{
    if (__builtin_popcount(mask) == n) return 0;
    if (indeks > m) return INF;
    if (dp[indeks][mask] != -1) return dp[indeks][mask];
    int ret = INF;
    ret = min(ret,rec(indeks + 1,mask));
    ret = min(ret,cost[indeks] + rec(indeks + 1,mask | tab[indeks]));
    return dp[indeks][mask] = ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++)
    {
        int k;
        cin >> cost[i] >> k;
        for (int j = 1 ; j <= k ; j++)
        {
            int ta;
            cin >> ta;
            --ta;
            tab[i] |= (1 << ta);
        }
    }
    memset(dp,-1,sizeof(dp));
    int ans = rec(1,0);
    if (ans == INF)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}