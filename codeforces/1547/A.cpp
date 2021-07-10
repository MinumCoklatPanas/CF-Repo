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
    int xA,yA,xB,yB,xF,yF;
    cin >> xA >> yA >> xB >> yB >> xF >> yF;
    int ans;
    if (xA == xB)
    {
        if (xF == xA)
        {
            if (min(yA,yB) <= yF && yF <= max(yA,yB))
            {
                ans = abs(yB - yA) + 2;
            }
            else
            {
                ans = abs(yB - yA);
            }
        }
        else
            ans = abs(yB - yA);
    }
    else
    if (yA == yB)
    {
        if (yF == yA)
        {
            if (min(xA,xB) <= xF && xF <= max(xA,xB))
            {
                ans = abs(xB - xA) + 2;
            }
            else
            {
                ans = abs(xB - xA);
            }
        }
        else
            ans = abs(xB - xA);
    }
    else
        ans = abs(xB - xA) + abs(yB - yA);
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