#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int long long

typedef tree<int, null_type, less<int>,
rb_tree_tag,tree_order_statistics_node_update>
ordered_set;

bool cmp(pair<int,int> a,pair<int,int> b)
{
    return (a.second > b.second);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector< pair<int,int> > tab;
    set<int> yVals;
    ordered_set xVals;
    for (int i = 1 ; i <= n ; i++)
    {
        int x,y;
        cin >> x >> y;
        tab.push_back({x,y});
        yVals.insert(-y);
    }
    sort(tab.begin(),tab.end(),cmp);
    int ix = 0;
    int ans = 0;
    // for (auto it : tab)
    //     cout << it.first << " " << it.second << endl;
    for (auto it : yVals)
    {
        vector< pair<int,int> > tmp;
        while (ix < tab.size() && tab[ix].second == -it)
        {
            tmp.push_back(tab[ix]);
            ++ix;
        }
        sort(tmp.begin(),tmp.end());
        tmp.push_back({INFF,INFF});
        for (int i = 0 ; i + 1 < tmp.size() ; i++)
        {
            xVals.insert(tmp[i].first);
            int l = xVals.order_of_key(tmp[i].first);
            int r = xVals.order_of_key(tmp[i + 1].first) - l;
            ans += (l + 1) * r;
        }
    }
    cout << ans << endl;
    return 0;
}