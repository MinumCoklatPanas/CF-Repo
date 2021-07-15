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
    vector<int> n(3),s(3,0);
    for (auto &it : n) cin >> it;
    vector< multiset<int> > ms(3);
    int sum = 0;
    for (int i = 0 ; i < 3 ; i++)
    {
        for (int j = 0 ; j < n[i] ; j++)
        {
            int ta;
            cin >> ta;
            sum += ta;
            ms[i].insert(ta);
            s[i] += ta;
        }
    }
    int ans = 0;
    for (int mn = 0 ; mn < 3 ; mn++)
    {
        for (int mx = 0 ; mx < 3 ; mx++) if (mn != mx)
        {
            int minVal = *ms[mn].begin();
            int maxVal = *ms[mx].rbegin();
            if (minVal > maxVal) continue;
            int cnt = 0;
            if (ms[mn].size() == 1)
            {
                cnt = sum - 2 * minVal;
            }
            else
            {
                ms[mn].erase(ms[mn].find(minVal));
                ms[mx].erase(ms[mx].find(maxVal));
                int tmp = sum - s[mn] - maxVal;
                int mini = INFF;
                for (int k = 0 ; k < 3 ; k++) if (k != mn && ms[k].size() > 0)
                {
                    mini = min(mini,*ms[k].begin());
                }
                tmp -= mini;
                int rem = s[mn] - minVal;
                int add = abs(mini - rem);
                cnt = tmp + add + maxVal - minVal;
                ms[mn].insert(minVal);
                ms[mx].insert(maxVal);
            }
            // cerr << mn << " " << mx << " " << cnt << endl;
            ans = max(ans,cnt);
        }
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