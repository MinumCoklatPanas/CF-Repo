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
    int q;
    cin >> q;
    vector<int> pref(q + 5,0);
    int ix = 0;
    for (int i = 1 ; i <= q ; i++)
    {
        int ask;
        cin >> ask;
        if (ask == 1)
        {
            int ta;
            cin >> ta;
            ++ix;
            pref[ix] = ta + pref[ix - 1]; 
        }
        else
        {
            int curMax = pref[ix] - pref[ix - 1];
            if (ix == 1)
            {
                cout << "0.000000\n";
                continue;
            }
            int l = 1;
            int r = ix - 1;
            const auto check = [&](int k) -> bool
            {
                double meanBef = 1.0 * (curMax + pref[k - 1]) / (k);
                double cur = pref[k] - pref[k - 1];
                return (cur <= meanBef);
            };
            // if (i == 6)
            // {
            //     cerr << l << " " << r << endl;
            //     continue;
            // }
            while (r - l > 1)
            {
                int mid = (l + r) >> 1;
                if (check(mid))
                    l = mid;
                else
                    r = mid - 1;
            }
            // cerr << l << " " << r << endl;
            cout << setprecision(9) << fixed;
            if (check(r))
            {
                double mean = 1.0 * (curMax + pref[r]) / (r + 1);
                mean = curMax - mean;
                cout << mean << endl;
            }
            else
            {
                double mean = 1.0 * (curMax + pref[l]) / (l + 1);
                mean = curMax - mean;
                cout << mean << endl;
            }
        }
    }
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