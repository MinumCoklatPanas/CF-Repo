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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int long long

int dp[200010];
int ada[200010];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> nyala;
    for (int i = 1 ; i <= n ; i++)
    {
        char ta;
        cin >> ta;
        ada[i] = (ta == '1');
        if (ada[i])
            nyala.push_back(i);
        dp[i] = INFF;
    }
    dp[n + 1] = 0;
    for (int i = n + 1 ; i > 1 ; i--)
    {
        dp[i - 1] = min(dp[i - 1],dp[i] + i - 1);
        int ix = lower_bound(nyala.begin(),nyala.end(),(i - 1) - k) - nyala.begin();
        if (ix != nyala.size())
        {
            int nearest = nyala[ix];
            // cout << i - 1 << " " << nearest << endl;
            if (abs(nearest - (i - 1)) <= k)
            {
                int nxt = max(1ll,nearest - k);
                dp[nxt] = min(dp[nxt],dp[i] + nearest);
            }
        }
        // cout << i << " " << dp[i] << endl;
    }
    cout << dp[1] << endl;
    return 0; 
}