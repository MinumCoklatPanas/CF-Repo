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
    int n;
    cin >> n;
    vector<int> tab(n);
    int gcd = 0;
    for (auto &it : tab) cin >> it,gcd = __gcd(gcd,it);
    if (gcd != 1)
    {
        cout << "YES\n";
        cout << 0 << endl;
        return;
    }
    const auto cnt = [&](vector<int> a) -> int
    {
        int ret = 0;
        for (int i = 0 ; i + 1 < n ; i++) if (a[i] & 1)
        {
            if (a[i + 1] % 2 == 0)
            {
                ret += 2;
                a[i] *= 2;
                a[i + 1] *= 2;
            }
            else
            {
                int mx = max(a[i],a[i + 1]);
                int mn = min(a[i],a[i + 1]);
                a[i] = mx - mn;
                a[i + 1] = mx + mn;
                ret += 1;
            }
        }
        if (a.back() % 2 == 1) ret += 2;
        return ret;
    };  
    cout << "YES\n";
    int ans = cnt(tab);
    reverse(tab.begin(),tab.end());
    ans = min(ans,cnt(tab));
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