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
    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    for (auto &it : h) cin >> it;
    pair<int,int> range = {max(h[0] - k + 1,0ll),h[0] + k - 1};
    for (int i = 1 ; i < n ; i++)
    {
        int mn = h[i];
        int mx = h[i] + ((k - 1) * (i != n - 1));
        // cerr << range.first << " " << range.second << " " << mn << " " << mx << " " << i << endl;
        if (mn > range.second || mx < range.first)
        {
            cout << "NO\n";
            return;
        }
        range.first = max(range.first,mn);
        range.second = min(range.second,mx);
        range.second += k - 1;
        range.first -= k;
        range.first++;
        if (range.first < 0) range.first = 0;
    }
    cout << "YES\n";
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