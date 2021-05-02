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

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m,n,k,t;
    cin >> m >> n >> k >> t;
    vector<int> tab(m);
    for (auto &it : tab) cin >> it;
    vector<int> l(k),r(k),d(k);
    for (int i = 0 ; i < k ; i++) cin >> l[i] >> r[i] >> d[i];
    sort(tab.begin(),tab.end());
    reverse(tab.begin(),tab.end());
    const auto can = [&](int x) -> bool
    {
        if (x == 0) return 1;
        int mn = tab[x - 1];
        vector<pair<int,int>> segments;
        for (int i = 0 ; i < k ; i++)
        {
            if (d[i] > mn)
            {
                segments.push_back({l[i],r[i]});
            }
        }
        if (segments.size() < 1) return 1;
        sort(segments.begin(),segments.end());
        int cost = n + 1;
        pair<int,int> cur = segments[0];
        // cout << cur.first << " " << cur.second << endl;
        for (auto it : segments)
        {
            if (it.first <= cur.second)
                cur.second = max(cur.second,it.second);
            else
            {
                cost += (cur.second - cur.first + 1) * 2;
                cur = it;
            }
        }
        cost += (cur.second - cur.first + 1) * 2;
        return (cost <= t);
    };
    // cout << can(5) << endl;
    // return 0;
    int lo = 0;
    int hi = m;
    while (hi - lo > 1)
    {
        int mid = (lo + hi) >> 1;
        if (can(mid))
            lo = mid;
        else
            hi = mid - 1;
    }
    if (can(hi))
        cout << hi << endl;
    else
        cout << lo << endl;
    return 0;
}