#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
#define int long long
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 5e6;
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

int frek[MAXN + 10];
int dp[MAXN + 10]; //{panjang,ambil}
int dp2[MAXN + 10];
int taken[MAXN + 10];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        frek[ta]++;
    }
    int ans = 0;
    for (int i = MAXN ; i >= 1 ; i--)
    {
        int totKelipatan = 0;
        for (int j = i + i ; j <= MAXN ; j += i)
            totKelipatan += frek[j];
        taken[i] = totKelipatan + frek[i];
        if (taken[i] == 0) continue;
        int ambil = 0;
        for (int j = i ; j <= MAXN ; j += i) if (dp[j])
        {
            // if (dp[j] > dp[i] || (dp[j] == dp[i] && taken[j] < ambil))
            // {
            //     dp[i] = max(dp[i],dp[j]);
            //     ambil = taken[j];
            // }
            int sisa = totKelipatan - taken[j];
            int tmp = dp[j] + sisa * i;
            // if (i == 1250000 && tmp > 0) cerr << j << ": " << tmp << endl; 
            dp[i] = max(dp[i],tmp);
        }
        // cerr << i << ": " << dp[i] << " " << totKelipatan << endl;
        // int sisa = totKelipatan - (ambil + frek[i]);
        // dp[i] += frek[i] * i;
        // if (i == 6)
        //     cerr << dp[i] << endl;
        // dp[i] += sisa * i;
        // if (i == MAXN)
        //     cerr << frek[i] * i << endl;
        dp[i] = dp[i] + frek[i] * i;
        // cerr << i << ": " << dp[i] << " " << endl;
        ans = max(ans,dp[i] + (n - totKelipatan - frek[i]));
    }
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