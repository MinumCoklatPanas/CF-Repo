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
    string s;
    cin >> s;
    int n = s.length();
    int ans = 1;
    string l;
    l += s[0];
    int ptr = 1;
    while (ptr < n && s[ptr] == '0')
    {
        l += s[ptr];
        ++ptr;
    }

    const auto can = [](string a,string b) -> bool
    {
        if (a.length() == b.length())
        {
            return a[0] >= b[0];
        }
        else
            return (a.length() > b.length());
    };

    while (ptr < n)
    {
        string r;
        r += s[ptr];
        ++ptr;
        // cerr << l << " " << r << endl;
        while (ptr < n && s[ptr] == '0')
        {
            r += s[ptr];
            ++ptr;
        }
        if (can(l,r))
        {
            ++ans;
            l += r;
        }
        else
        {
            ans = 1;
            l += r;
        }
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