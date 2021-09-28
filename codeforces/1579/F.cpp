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
    int n,d;
    cin >> n >> d;
    vector<int> tab(n);
    for (auto &it : tab) cin >> it;
    vector<bool> vis(n,0);
    int ans = 0;
    for (int i = 0 ; i < n ; i++) if (!vis[i])
    {
        int cur = i;
        vector<int> order;
        while (!vis[cur])
        {
            vis[cur] = 1;
            order.push_back(cur);
            cur -= d;
            cur %= n;
            if (cur < 0)
                cur += n;
        }
        bool ada0 = 0;
        for (auto it : order)
        {
            if (tab[it] == 0)
            {
                ada0 = 1;
                break;
            }
        } 
        if (!ada0)
        {
            cout << -1 << endl;
            return;
        }
        // for (auto it : order)
        //     cerr << it << " ";
        // cerr << endl;
        int sz = order.size();
        for (int j = 0 ; j < sz ; j++)
            order.push_back(order[j]);
        vector<int> pos0;
        for (int j = 0 ; j < order.size() ; j++) if (tab[order[j]] == 0)
        {
            pos0.push_back(j);
        }
        int mx = -INF;
        for (int j = 0 ; j < sz ; j++) if (tab[order[j]] == 1)
        {
            int nextIx = lower_bound(pos0.begin(),pos0.end(),j) - pos0.begin();
            mx = max(mx,pos0[nextIx] - j);
        }
        ans = max(ans,mx);
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