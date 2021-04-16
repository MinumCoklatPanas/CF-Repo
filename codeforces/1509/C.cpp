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

int tab[2010];
int kiri_kanan[2010][2010];
int kanan_kiri[2010][2010];
int pref[2010];
int suf[2010];
int dp[2010][2010];
int n;

int rec(int l,int r)
{
    if (l == 1 && r == n) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    int ret = INFF;
    if (r < n)
        ret = min(ret,tab[r + 1] - tab[l] + rec(l,r + 1));
    if (l > 1)
        ret = min(ret,tab[r] - tab[l - 1] + rec(l - 1,r));
    return dp[l][r] = ret; 
}

void solve()
{
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> tab[i];
    sort(tab + 1,tab + n + 1);
    memset(dp,-1,sizeof(dp));
    int ans = INFF;
    for (int i = 1 ; i <= n ; i++)
        ans = min(ans,rec(i,i));
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}