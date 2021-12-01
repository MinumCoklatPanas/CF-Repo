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
    string x1,x2;
    int p1,p2;
    cin >> x1 >> p1 >> x2 >> p2;
    int len1 = x1.length() + p1;
    int len2 = x2.length() + p2;
    if (len1 < len2)
        cout << "<\n";
    else
    if (len1 > len2)
        cout << ">\n";
    else
    {
        while (x1.back() == '0') x1.pop_back();
        while (x2.back() == '0') x2.pop_back();
        // cerr << "yo\n";
        if (x1 == x2)
            cout << "=\n";
        else
        if (x1 > x2)
            cout << ">\n";
        else
            cout << "<\n";
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