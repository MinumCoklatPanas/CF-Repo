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
    int n,m,ta,tb,k;
    cin >> n >> m >> ta >> tb >> k;
    vector<int> a(n),b(m);
    for (auto &it : a) cin >> it;
    for (auto &it : b) cin >> it;
    if (k >= n || k >= m)
    {
        cout << -1 << endl;
        return;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int mx = 0;
    for (int i = 0 ; i < n ; i++)
    {
        int rem = k - i;
        if (rem < 0) break;
        int ix = lower_bound(b.begin(),b.end(),a[i] + ta) - b.begin();
        if (ix + rem >= m)
        {
            cout << -1 << endl;
            return;
        }
        mx = max(mx,b[ix + rem] + tb);
    }

    // const auto bf = [&]() -> int 
    // {
        
    // };

    cout << mx << endl;
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