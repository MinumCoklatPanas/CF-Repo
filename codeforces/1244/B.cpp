// time-limit: 1000
// problem-url: https://codeforces.com/contest/1244/problem/B
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s[0] == '1' || s.back() == '1')
    {
        cout << 2 * n << endl;
    }
    else
    {
        int ans = n;
        for (int i = 0 ; i < n ; i++) ans += (s[i] == '1');
        const auto cnt = [&]() -> int
        {
            for (int i = n - 1 ; i >= 0 ; i--) if (s[i] == '1')
                return (i + 1) * 2;
            return 0;
        };
        ans = max(ans,cnt());
        reverse(s.begin(),s.end());
        ans = max(ans,cnt());
        cout << ans << endl;
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