#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

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
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

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
    int n,k;
    cin >> n >> k;
    vector<int> tab(n);
    for (auto &it : tab) cin >> it;
    vector<int> threshold(k);
    for (auto &it : threshold) cin >> it;
    sort(tab.begin(),tab.end());
    int mx = 0;
    
    const auto cei = [](int x,int y) -> int
    {
        return (x / y) + (x % y != 0);
    };

    for (int i = 1 ; i <= k ; i++)
    {
        int more = lower_bound(tab.begin(),tab.end(),i) - tab.begin();
        more = n - more;
        mx = max(mx,cei(more,threshold[i - 1]));
    }
    cout << mx << endl;
    vector< vector<int> > ans(mx);
    for (int i = 0 ; i < n ; i++)
    {
        ans[i % mx].push_back(tab[i]);
    }
    for (auto it : ans)
    {
        cout << it.size() << " ";
        for (auto it2 : it)
            cout << it2 << " ";
        cout << endl;
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