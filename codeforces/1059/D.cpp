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

struct point
{
    double x,y;
    point(){};
    point(double _x,double _y)
    {
        x = _x;
        y = _y;
    }
};


void solve()
{
    int n;
    cin >> n;
    vector<point> tab(n);
    bool pos = 0;
    bool neg = 0;
    for (auto &it : tab) 
    {
        cin >> it.x >> it.y;
        pos |= (it.y > 0);
        neg |= (it.y < 0);
    }

    if (pos && neg)
    {
        cout << -1 << endl;
        return;
    }

    if (neg)
    {
        for (auto &it : tab) it.y *= -1;
    }

    const auto minRad = [&](double x,point p) -> double
    {
        double atas = ((x - p.x) * (x - p.x)) + p.y * p.y;
        double bawah = 2 * p.y;
        return atas / bawah;
    };

    const auto f = [&](double x) -> double
    {
        double ret = 0.0;
        for (auto it : tab)
        {
            double tmp = minRad(x,it);
            ret = max(ret,tmp);
        }
        return ret;
    };

    // cout << f(0.5) << endl;

    double l = -1e17, r = 1e17;
    for (int i = 1 ; i <= 300 ; i++)
    {
        // cout << l << " " << r << endl;
        double t1 = l + (r - l) / 3.0;
        double t2 = l + (r - l) * 2.0 / 3.0;
        double f1 = f(t1);
        double f2 = f(t2);
        if (f1 > f2)
            l = t1;
        else
            r = t2;
    }
    double ans = f(l);
    cout << setprecision(9) << fixed;
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