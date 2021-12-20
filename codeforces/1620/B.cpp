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
    int w,h;
    cin >> w >> h;
    const auto process = [&](int pengali) -> int
    {
        int k;
        cin >> k;
        vector<int> tab(k);
        for (auto &it : tab) cin >> it;
        return pengali * (tab[k - 1] - tab[0]);
    };  
    int ans = 0;
    ans = max(ans,process(h));
    ans = max(ans,process(h));
    ans = max(ans,process(w));
    ans = max(ans,process(w));
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