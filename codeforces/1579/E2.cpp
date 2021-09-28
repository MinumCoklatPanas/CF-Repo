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
    vector<int> tab(n);
    vector<int> compress;
    for (auto &it : tab) 
    {
        cin >> it;
        compress.push_back(it);
    }
    // sort(compress.begin(),compress.end());
    // compress.erase(unique(compress.begin(),compress.end()),compress.end());
    // map<int,int> mp;
    // sz = compress.size();
    // for (int i = 0 ; i < compress.size() ; i++)
    // { 
    //     mp[compress[i]] = i + 1;
    // }
    ordered_set avl;
    int ans = 0;
    for (auto it : tab)
    {
        int kurang = avl.order_of_key(it);
        int lebih = avl.size() - avl.order_of_key(it + 1);
        ans += min(kurang,lebih);
        avl.insert(it);
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