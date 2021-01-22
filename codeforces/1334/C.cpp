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

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    int sum = 0;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> a[i] >> b[i];
        sum += a[i];
    } 
    int ans = sum;
    int cur = 0;
    for (int i = 0 ; i + 1 < n ; i++)
    {
        cur += min(b[i],a[i + 1]);
    }
    int mx = cur;
    for (int i = 1 ; i < n ; i++)
    {
        cur -= min(a[i],b[i - 1]);
        if (i == 1)
            cur += min(a[i - 1],b[n - 1]);
        else
            cur += min(a[i - 1],b[i - 2]);
        mx = max(mx,cur);
    }
    ans -= mx;
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}