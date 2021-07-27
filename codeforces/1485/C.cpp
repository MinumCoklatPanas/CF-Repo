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
    // for (int i = 1 ; i <= 1000 ; i++)
    // {
    //     int cnt = 0;
    //     for (int j = 1 ; j <= 1000 ; j++)
    //     {
    //         if (j % i == j / i)
    //         {
    //             // cout << i << " " << j << endl;
    //             ++cnt;
    //         }
    //     }
    //     cout << i << " " << cnt << endl;
    // }
    int x,y;
    cin >> x >> y;
    int ans = 0;
    int cur = 1;
    for (cur = 1 ; cur <= y; cur++)
    {
        if (cur * (cur - 1) + (cur - 1) > x) break;
        ans += cur - 1;
    }
    int lst = cur - 2;
    for (int i = lst ; i >= 1 ; i--)
    {
        if (cur > y) break;
        int l = cur;
        int r = y;
        const auto valid = [&](int k) -> bool
        {
            return (((x / (k + 1))) == i);
        };

        while (r - l > 1)
        {
            // cerr << l << " " << r << endl;
            int mid = (l + r) >> 1;
            if (valid(mid))
                l = mid;
            else
                r = mid -1;
        }
        // cerr << i << " " << l << " " << " " << r << endl;
        if (valid(r))
        {
            ans += (r - cur + 1) * i;
            cur = r + 1;
        }
        else
        if (valid(l))
        {
            ans += (l - cur + 1) * i;
            cur = l + 1;
        }
        // cerr << cur << endl;
        // cerr << "-------------------------\n";
        // break;
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