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

int dp[100010];
int n;
int dp2[100010];
string s;

int rec(int ix)
{
    if (ix < 1) return 1;
    if (dp2[ix] != -1) return dp2[ix];
    int ret = 0;
    char res = s[ix - 1] + s[ix - 2] - '0';
    if (res == '9')
    {
        if (dp[ix - 1] == dp[ix])
            ret += rec(ix - 1);
        if (dp[ix - 2] + 1 == dp[ix])
            ret += rec(ix - 2);
    }
    else
        ret += rec(ix - 1);
    return dp2[ix] = ret;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dp2,-1,sizeof(dp2));
    cin >> s;
    n = s.length();
    for (int i = 1 ; i < s.length() ; i++)
    {
        // cout << (char)(s[i] + s[i - 1]) << endl;
        char res = s[i] + s[i - 1] - '0';
        // cout << res << endl;
        if (res != '9')
            dp[i + 1] = dp[i];
        else
        {
            // cout << i << " masuk\n";
            dp[i + 1] = max(dp[i - 1] + 1,dp[i]);
        }
    }
    // for (int i = 1 ; i <= n ; i++)
    //     cout << dp[i] << " ";
    // cout << endl;
    int ans = rec(n);
    cout << ans << endl;
    return 0;
}