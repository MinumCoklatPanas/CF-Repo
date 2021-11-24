#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
typedef tree<int, null_type, less<int>,
rb_tree_tag,tree_order_statistics_node_update> ordered_set;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    map<int,int> mp;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        mp[ta]++;
    }
    int ans = (n * (n - 1)) / 2;
    for (auto it : mp)
    {
        ans -= (it.second * (it.second - 1)) / 2;
    }
    cout << ans << endl;
    return 0;
}