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

int tab[110][110];
int dp[2][110][110][30]; //[who,posA,posB,bef]
int in[110];
int n,m;

int rec(int who,int posA,int posB,int bef)
{
    if (dp[who][posA][posB][bef] != -1) return dp[who][posA][posB][bef];
    int ret = 0;
    if (who == 0)
    {
        for (int i = 1 ; i <= n ; i++) if (tab[posA][i] >= bef)
        {
            int tmp = rec(who ^ 1,i,posB,tab[posA][i]);
            if (tmp == 0)
            {
                ret = 1;
                break;
            }
        }
    }
    else
    if (who == 1)
    {
        for (int i = 1 ; i <= n ; i++) if (tab[posB][i] >= bef)
        {
            int tmp = rec(who ^ 1,posA,i,tab[posB][i]);
            if (tmp == 0)
            {
                ret = 1;
                break;
            }
        }
    }
    return dp[who][posA][posB][bef] = ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(tab,-1,sizeof(tab));
    memset(dp,-1,sizeof(dp));
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++)
    {
        int u,v;
        char c;
        cin >> u >> v >> c;
        tab[u][v] = c - 'a' + 1;
    }
    // cout << rec(1,0) << endl;
    // return 0;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            int ret = rec(0,i,j,0);
            if (ret)
                cout << "A";
            else    
                cout << "B";
            if (j == n)
                cout << "\n";
        }   
    }
    return 0;
}