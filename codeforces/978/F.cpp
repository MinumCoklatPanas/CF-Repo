#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
typedef tree<
int,
null_type,
less_equal<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
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

vector<int> kiri[200010],kanan[200010];
int tab[200010];

void solve()
{
    int n,k;
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++) cin >> tab[i];
    for (int i = 1 ; i <= k ; i++)
    {
        int u,v;
        cin >> u >> v;
        if (u < v) swap(u,v);
        kiri[u].push_back(v);
        kanan[v].push_back(u);
    }
    vector<int> ans(n + 5,0);
    ordered_set avl;
    for (int i = 1 ; i <= n ; i++)
    {
        ans[i] += avl.size() - avl.order_of_key(tab[i]);
        for (auto it : kiri[i]) if (tab[i] > tab[it]) ans[i]++;
        avl.insert(tab[i]);
        // cerr << i << " " << ans[i] << endl;
    }
    avl.clear();
    for (int i = n ; i >= 1 ; i--)
    {
        ans[i] += avl.size() - avl.order_of_key(tab[i]);
        for (auto it : kanan[i]) if (tab[i] > tab[it]) ans[i]++;
        avl.insert(tab[i]);
    }
    for (int i = 1 ; i <= n ; i++)
        cout << n - 1 - ans[i] << " ";
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