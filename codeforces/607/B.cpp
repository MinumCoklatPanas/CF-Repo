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

int n;
int tab[510];
bool isPalin[510][510];
int longestPalin[510][510];
int dp[510][510];

void solve()
{
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> tab[i];
    for (int i = 1 ; i <= n ; i++) isPalin[i][i] = 1;
    for (int i = 1 ; i + 1 <= n ; i++) isPalin[i][i + 1] = (tab[i] == tab[i + 1]);
    for (int len = 3 ; len <= n ; len++)
    {
        for (int j = 1 ; j + len - 1 <= n ; j++)
        {
            if (tab[j] == tab[j + len - 1])
                isPalin[j][j + len - 1] = isPalin[j + 1][j + len - 2];
            else
                isPalin[j][j + len - 1] = 0;
        }
    }
    for (int i = 1 ; i <= n ; i++)
    {
        longestPalin[i][i] = i;
        for (int j = i + 1 ; j <= n ; j++)
        {
            longestPalin[i][j] = (isPalin[i][j] ? j : longestPalin[i][j - 1]);
        }
    }
    for (int i = 1 ; i <= n ; i++) dp[i][i] = 1;
    for (int i = 1 ; i + 1 <= n ; i++) 
    {
        dp[i][i + 1] = (isPalin[i][i + 1] ? 1 : 2);
        // cerr << i << " " << dp[i][i + 1] << endl;
    }
    // cerr << endl;
    for (int len = 3 ; len <= n ; len++)
    {
        for (int i = 1 ; i + len - 1 <= n ; i++)
        {
            int l = i;
            int r = i + len - 1;
            dp[l][r] = dp[l + 1][r] + 1;
            if (tab[l] == tab[l + 1])
            {
                dp[l][r] = min(dp[l][r],dp[l + 2][r] + 1);
                // cerr << l << " " << r << " masuk " << dp[l + 2][r] << " " << dp[l + 1][r] << endl;
            }
            for (int j = l + 2 ; j <= r ; j++) if (tab[l] == tab[j])
            {
                dp[l][r] = min(dp[l][r],dp[l + 1][j - 1] + dp[j + 1][r]);
            }
            // cerr << l << " " << r << ": " << dp[l][r] << endl;
        }
    }
    cout << dp[1][n] << endl;
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