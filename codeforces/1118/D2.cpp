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
    vector<int> tab(n);
    int sum = 0;
    for (auto &it : tab)
    { 
        cin >> it;
        sum += it;
    }
    if (sum < m)
    {
        cout << -1 << endl;
        return;
    }
    sort(tab.begin(),tab.end());
    reverse(tab.begin(),tab.end());
    int l = 1;
    int r = n;
    const auto check = [&](int x) -> bool
    {
        int ret = 0;
        for (int i = 0 ; i <  n ; i++) ret += max(0ll,tab[i] - (i / x));
        return (ret >= m);
    };
    while (r - l > 1)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    if (check(l))
        cout << l << endl;
    else
        cout << r << endl;
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