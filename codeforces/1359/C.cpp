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
const double EPS = 1e-15;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

double f(int x,int h,int c)
{
    // cout << ((0.5 * (x - 1)) * (h + c) + h) / x << endl;
    return (((0.5 * (x - 1)) * (h + c)) + h) / x;
}

int bf(int h,int c,int t)
{
    int ans = 0;
    double mn = INF;
    double sum = 0.0;
    for (int i = 1 ; i <= 1000 ; i++)
    {
        if (i & 1)
            sum += h;
        else
            sum += c;
        double mean = (sum / i);
        double diff = fabs(mean - t);
        // cout << i << " " << mean << endl;
        if (diff < mn)
        {
            mn = diff;
            ans = i;
        } 
    }
    return ans;
}

void solve()
{
    cout << setprecision(20) << fixed << endl;
    int h,c,t;
    cin >> h >> c >> t;
    if (h + c >= 2 * t)
    {
        cout << bf(h,c,t) << endl;
        return;
    }
    double k = (double)(c - h) / (double)(c + h - 2 * t);
    int ans = -1;
    // cout << k << endl;
    // double tmp = f(k,h,c);
    double diff = INF;
    for (int i = max(1ll,(int)k + 10) ; i >= max(1ll,(int)k - 10) ; i--)
    {
        double tmp = f(i,h,c);
        if (i % 2 == 0)
            tmp = 0.5 * (h + c);
        double tmp_diff = fabs(tmp - t);
        // cout << i << " " << tmp_diff << endl;
        if (tmp_diff - diff < EPS)
        {
            diff = tmp_diff;
            ans = (i % 2 == 1 ? i : 2);
        }
    }
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
    // double sum = 0;
    // double h = 30.0;
    // double c = 10.0;
    // for (int i = 1 ; i <= 100 ; i++)
    // {
    //     if (i & 1)
    //         sum += h;
    //     else
    //         sum += c;
    //     cout << (sum / i) << endl;
    //     // cout << i << ": " << (sum / i) << endl;
    // }
    return 0;
}