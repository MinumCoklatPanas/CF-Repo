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
    int n,m;
    cin >> n >> m;
    vector<int> a(n),b(n);
    vector<int> order(n);
    for (int i = 0 ; i < n ; i++)
    { 
        cin >> a[i] >> b[i];
        order[i] = i;
    }
    sort(order.begin(),order.end(),[&](int x,int y)
    {
        return (a[x] - b[x]) < (a[y] - b[y]);
    });
    int aAtas = 0,bAtas = 0,aBawah = 0,bBawah = 0;
    for (int i = 0 ; i < n ; i++) aBawah += a[i], bBawah += b[i];
    vector<int> ans(n,0);
    for (int i = 0 ; i < n ; i++)
    {
        aBawah -= a[order[i]];
        bBawah -= b[order[i]];
        ans[order[i]] += (n - i - 1) * a[order[i]] + bBawah;
        ans[order[i]] += i * b[order[i]] + aAtas;
        aAtas += a[order[i]];
        bAtas += b[order[i]];
    }
    // for (int i = 0 ; i < n ; i++)
    //     cerr << ans[i] << " ";
    // cerr << endl;
    for (int i = 0 ; i < m ; i++)
    {
        int u,v;
        cin >> u >> v;
        --u; --v;
        int cost = min(a[u] + b[v],a[v] + b[u]);
        ans[u] -= cost;
        ans[v] -= cost;
    }
    for (int i = 0 ; i < n ; i++)
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