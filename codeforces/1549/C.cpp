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

multiset<int> ms[200010];
int ans;
bool isGood[200010];

void update(int x)
{
    if (isGood[x])
    {
        if (!ms[x].empty() && *ms[x].rbegin() > x)
        {
            --ans;
            isGood[x] = 0;
        }
    }
    else
    {
        if ((!ms[x].empty() && *ms[x].rbegin() < x) || (ms[x].empty()))
        {
            ++ans;
            isGood[x] = 1;
        }
    }
}

void addEdge(int x,int y)
{
    ms[x].insert(y);
    ms[y].insert(x);
    update(x);
    update(y);
}

void removeEdge(int x,int y)
{
    ms[x].erase(ms[x].find(y));
    ms[y].erase(ms[y].find(x));
    update(x);
    update(y);
}

void solve()
{
    int n,m;
    cin >> n >> m;
    ans = n;
    memset(isGood,1,sizeof(isGood));
    for (int i = 1 ; i <= m ; i++)
    {
        int u,v;
        cin >> u >> v;
        addEdge(u,v);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int ask;
        cin >> ask;
        if (ask == 3)
            cout << ans << endl;
        else
        if (ask == 1)
        {
            int u,v;
            cin >> u >> v;
            addEdge(u,v);
        }
        else
        {
            int u,v;
            cin >> u >> v;
            removeEdge(u,v);
        }
    }
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