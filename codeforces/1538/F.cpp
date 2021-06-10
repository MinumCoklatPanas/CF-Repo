// time-limit: 2000
// problem-url: https://codeforces.com/contest/1538/problem/F
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

void bf()
{
    vector<int> pref(10000,0);
    pref[1] = 0;
    cout << 1 << " " << 1 << endl;
    for (int i = 2 ; i <= 10000 ; i++)
    {
        string s = to_string(i - 1);
        reverse(s.begin(),s.end());
        int add = 1;
        int ptr = 0;
        while (ptr < s.length() && s[ptr] == '9') ++ptr,++add;
        pref[i] = pref[i - 1] + add;
        cerr << i << " " << add << endl;
        cout << i << " " << pref[i] << endl;
    }
}

void solve()
{
    int l,r;
    cin >> l >> r;
    const auto f = [&](int x) -> int
    {
        int pengali = 10;
        int ret = 0;
        for (int i = 1 ; i < 10 ; i++)
        {
            ret += x / pengali;
            pengali *= 10;
        }
        return ret;
    };
    int ans = r - l;
    ans += f(r);
    ans -= f(l);
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