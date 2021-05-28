// time-limit: 1000
// problem-url: https://codeforces.com/contest/1526/problem/C2
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

void solve()
{
    int n;
    cin >> n;
    vector<int> tab(n);
    for (auto &it : tab) cin >> it;
    priority_queue<int> neg;
    int ans = 0;
    int cur = 0;
    for (int i = 0 ; i < n ; i++)
    {
        int ta = tab[i];
        if (ta >= 0)
        {
            cur += ta;
            ans++;
        }
        else
        {
            int after = cur + ta;
            // cout << i << " " << after << endl;
            if (after >= 0)
            {
                // cout << "yo\n";
                ans++;
                cur = after;
                neg.push(-ta);
            }
            else
            if (neg.size() > 0)
            {
                int mx = neg.top();
                // cout << i << " " << after << " " << mx << endl;
                if (mx > -ta && after + mx >= 0)
                {
                    cur = after + mx;
                    // cout << i << " " << after<< " " << mx << " " << ta << endl;
                    neg.pop();
                    neg.push(-ta);
                }
            }
        }
        // cerr << i << " " << ans << " "  << cur << endl;
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