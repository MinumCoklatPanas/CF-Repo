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

int a[210];
int b[210];
int dp[210][1100]; //[indeks][hasil]
int n,m;

int rec(int indeks,int hasil)
{
    if (indeks > n) return hasil;
    if (dp[indeks][hasil] != -1) return dp[indeks][hasil];
    int ret = 1024;
    for (int i = 1 ; i <= m ; i++)
    {
        ret = min(ret,rec(indeks + 1,hasil | (a[indeks] & b[i])));
    }
    return dp[indeks][hasil] = ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dp,-1,sizeof(dp));
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
        cin >> a[i];
    for (int i = 1 ; i <= m ; i++)
        cin >> b[i];
    int ans = rec(1,0);
    cout << ans << endl;    
    return 0;
}
