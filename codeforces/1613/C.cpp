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
    int n,h;
    cin >> n >> h;
    vector<int> tab(n);
    for (auto &it : tab) cin >> it;
    tab.push_back(4 * INFF);
    const auto can = [&](int x) -> bool
    {   
        int tot = 0;
        for (int i = 0 ; i < n ; i++)
        {
            int nxt = tab[i + 1];
            int diff = nxt - tab[i];
            int dmg = min(diff,x);
            tot += dmg;
            // cerr << i << " " << dmg << " " << tot << " " << diff << endl;
            if (tot >= h) return true;
        }   
        return false;
    };
    // can(469);
    // return;
    int l = 1;
    int r = INFF;
    while (r - l > 1)
    {
        int mid = (l + r) >> 1;
        if (can(mid))
            r = mid;
        else
            l = mid + 1;
    }
    if (can(l))
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