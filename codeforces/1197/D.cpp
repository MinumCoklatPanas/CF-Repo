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

int tab[300010];
int dp[300010];
int pref[300010];

int get(int l, int r)
{
    return (pref[r] - pref[l - 1]);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> tab[i];
        pref[i] = tab[i] + pref[i - 1];
    }
    int ans = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        dp[i] = max(dp[i], tab[i] - k);
        for (int j = i - 1 ; i - j <= m && j >= 0 ; j--)
        {
            dp[i] = max(dp[i], dp[j] + get(j + 1, i) - k);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}