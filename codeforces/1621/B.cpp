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

struct dt
{
    int l,r,c;
    dt(){}
    dt(int _l,int _r,int _c)
    {
        l = _l; r = _r; c = _c;
    }
    bool operator< (dt& other) const
    {
        if (l == other.l) return c < other.c;
        else return l < other.l;
    }
};


void solve()
{
    int n;
    cin >> n;
    deque<dt> dq;
    int l,r,c;
    cin >> l >> r >> c;
    cout << c << endl;
    dq.push_back(dt(l,r,c));
    dt leftMost = dt(l,r,c);
    dt rightMost = dt(l,r,c);
    dt longest = dt(l,r,c);
    int cur = c;
    int curMax = r;
    for (int i = 1 ; i < n ; i++)
    {
        cin >> l >> r >> c;
        if (l < leftMost.l || (l == leftMost.l && c < leftMost.c)) leftMost = dt(l,r,c);
        if (r > rightMost.r || (r == rightMost.r && c < rightMost.c)) rightMost = dt(l,r,c);
        if (l == leftMost.l && r == rightMost.r)
        {
            if (longest.l == l && longest.r == r) longest.c = min(c,longest.c);
            else longest = dt(l,r,c);
        }
        int ans = leftMost.c + rightMost.c;
        if (leftMost.l == longest.l && rightMost.r == longest.r) ans = min(ans,longest.c);
        cout << ans << endl;
        // cout << cur << endl;
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