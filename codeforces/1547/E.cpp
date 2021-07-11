#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
        scanf("%lld",&t);
        return t;
    }
    else return 1;
}

void solve()
{
    int n,k;
    scanf("%lld %lld",&n,&k);
    // cin >> n >> k;
    vector<int> a(k);
    vector<int> t(k);
    vector<int> dist(n + 3,INFF);
    vector<bool> vis(n + 3,0);
    for (auto &it : a) 
    {
        scanf("%lld",&it);
    }
    for (auto &it : t) 
    {
        scanf("%lld",&it);
    }
    priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
    for (int i = 0 ; i < k ; i++) 
    {
        // cerr << a[k] << " " << t[k] << endl;
        pq.push({t[i],a[i]});
    }
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        int temp = cur.first;
        int ix = cur.second;
        // cerr << temp << " " << ix << endl;
        if (vis[ix]) continue;
        dist[ix] = temp;
        vis[ix] = 1;
        if (ix - 1 > 0)
        {
            if (dist[ix - 1] >= temp + 1)
            {
                dist[ix - 1] = temp + 1;
                pq.push({temp + 1,ix - 1});
            }
        }
        // cerr << ix << " masuk\n";
        if (ix + 1 <= n)
        {
            if (dist[ix + 1] >= temp + 1)
            {
                dist[ix + 1] = temp + 1;
                pq.push({temp + 1,ix + 1});
            }
        }
    }
    for (int i = 1 ; i <= n ; i++)
        printf("%lld ",dist[i]);
    puts("");
}

signed main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int t = getTC();
    while (t--)
    {
        solve();
    }
    return 0;
}