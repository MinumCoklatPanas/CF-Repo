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
    string s;
    cin >> s;
    const auto fnd = [&](string t) -> int
    {
        int cur = 1;
        int pos = -1;
        for (int i = s.length() - 1 ; i >= 0 ; i--)
        {
            if (cur == 1 && s[i] == t[cur])
            {
                --cur;
                pos = i;
            }
            else
            if (cur == 0 && s[i] == t[cur])
            {
                // cerr << pos << " " << i << endl;
                int diff = pos - i - 1;
                return diff + (s.length() - 1 - pos);
            }
        }
        return INF;
    };
    int ans = fnd("00");
    // return;
    ans = min(ans,fnd("50"));
    ans = min(ans,fnd("25"));
    ans = min(ans,fnd("75"));
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