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

int tab[1010][1010];
int cnt[2][1010];
int dp[1010][2]; //[index][warna]
int n,m,x,y;

int rec(int index,int warna)
{
    if (index > m) return 0;
    if (m - index + 1 < x) return INF;
    if (dp[index][warna] != -1) return dp[index][warna];
    int tot = 0;
    for (int i = index ; i < min(index + x - 1,m) ; i++)
        tot += cnt[warna ^ 1][i];
    int ret = INF;
    for (int i = min(index + x - 1,m) ; i <= min(index + y - 1,m) ; i++)
    {
        tot += cnt[warna ^ 1][i];
        int change = (i - index + 1) * n - tot;
        // cout <<  index << " - " << i << " ganti " << change << ": " << warna << endl;
        ret = min(ret,change + rec(i + 1,warna ^ 1));
        
    }
    // cout << index << " " << warna << " " << ret << endl;
    return dp[index][warna] = ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> x >> y;
    assert(x <= m);
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= m ; j++)
        {
            char ta;
            cin >> ta;
            tab[i][j] = (ta == '.');
            cnt[tab[i][j]][j]++;
        }
    }
    memset(dp,-1,sizeof(dp));
    int a = rec(1,0);
    int b = rec(1,1);
    int ans = min(a,b);
    // cout << a << " " << b << endl;
    cout << ans << endl;
    return 0;
}