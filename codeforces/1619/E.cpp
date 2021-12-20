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
#define MULTI_TC 1

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

void solve()
{
    int n;
    cin >> n;
    vector<int> frek(n + 5,0);
    for (int i = 0 ; i < n ; i++)
    {
        int ta;
        cin >> ta;
        frek[ta]++;
    }
    if (frek[0] == 0)
    {
        cout << 0 << " ";
        for (int i = 1 ; i <= n ; i++)
            cout << -1 << " ";
        cout << endl;
        return;
    }
    auto frekTmp = frek;
    int last0 = -1;
    vector<int> dp(n + 5,-1); //dp[i] = langkah min supaya maxnya i
    priority_queue<int> pq;
    dp[0] = 0;
    if (frek[0] > 1) pq.push(0);
    for (int i = 1 ; i <= n ; i++)
    {
        dp[i] = dp[i - 1];
        if (frek[i] > 1)
        {
            // dp[i] += frek[i - 1];
            pq.push(i);
        }
        else
        if (frek[i] == 0)
        {
            if (pq.empty())
                dp[i] = -1;
            else
            {
                int nearest = pq.top();
                pq.pop();
                frekTmp[nearest]--;
                if (frekTmp[nearest] > 1) pq.push(nearest);
                dp[i] += i - nearest;
            }
        }
        if (dp[i] == -1) break;
        // cerr << i << " " << dp[i] << endl;
    }
    vector<int> ans(n + 5,-1);
    ans[0] = dp[0] + frek[0];
    for (int i = 1 ; i <= n ; i++)
    {
        if (dp[i - 1] == -1)
            ans[i] = -1;
        else
            ans[i] = dp[i - 1] + frek[i];
        if (ans[i] == -1)
            assert(ans[i + 1] == -1);
    }
    for (int i = 0 ; i <= n ; i++)
        cout << ans[i] << " ";
    cout << endl;
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