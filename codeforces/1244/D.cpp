// time-limit: 3000
// problem-url: https://codeforces.com/contest/1244/problem/D
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

vector<int> adj[100010];
int dp[100010][3][3];
int sum[100010][3];
int cost[100010][3];
int deg[100010];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> cost[i][0];
    for (int i = 1 ; i <= n ; i++) cin >> cost[i][1];
    for (int i = 1 ; i <= n ; i++) cin >> cost[i][2];
    for (int i = 1 ; i < n ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    queue<int> q;
    for (int i = 1 ; i <= n ; i++)
    {
        if (deg[i] == 1 && q.empty())
            q.push(i);
        if (deg[i] > 2)
        {
            cout << -1 << endl;
            return;
        }
    }
    vector<int> topo;
    int cur = q.front();
    int bef = cur;
    topo.push_back(cur);
    cur = adj[bef][0];
    for (int i = 1 ; i < n ; i++)
    {
        topo.push_back(cur);
        // cout << cur << " " << bef << " ";
        for (auto it : adj[cur]) if (it != bef)
        {
            // cout << it << endl;
            bef = cur;
            cur = it;
            break;
        }
    }
    const auto bf = [&](vector<int> tab) -> pair<int,pair<int,int>>
    {
        int ret = INFF;

        pair<int,pair<int,int>> res;
        for (int i = 0 ; i < 3 ; i++)
        {
            for (int j = 0 ; j < 3 ; j++) if (i != j)
            {
                int cnt = 0;
                cnt += cost[tab[0]][i];
                cnt += cost[tab[1]][j];
                int a = i;
                int b = j;
                for (int k = 2 ; k < n ; k++)
                {
                    int c = 3 - (a + b);
                    cnt += cost[tab[k]][c];
                    a = b;
                    b = c;
                }
                if (cnt < ret)
                {
                    ret = cnt;
                    res = {ret,{i,j}};
                }
            }
        }
        return res;
    };
    auto kiri = bf(topo);
    reverse(topo.begin(),topo.end());
    auto kanan = bf(topo);
    vector<int> ans(n + 1,-1);
    if (kiri.first < kanan.first)
    {
        cout << kiri.first << endl;
        int a = kiri.second.first;
        int b = kiri.second.second;
        ans[topo[0]] = a;
        ans[topo[1]] = b;
        for (int i = 2 ; i < n ; i++)
        {
            int c = 3 - (a + b);
            ans[topo[i]] = c;
            a = b;
            b = c;
        }
    }
    else
    {
        cout << kanan.first << endl;
        int a = kanan.second.first;
        int b = kanan.second.second;
        ans[topo[0]] = a;
        ans[topo[1]] = b;
        for (int i = 2 ; i < n ; i++)
        {
            int c = 3 - (a + b);
            ans[topo[i]] = c;
            a = b;
            b = c;
        }
    }
    for (int i = 1 ; i <= n ; i++)
    {
        assert(ans[i] != -1);
        cout << ans[i] + 1 << " ";
    }
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