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

struct exam
{
    int s,d,c,ix;
    exam(){}
};


void solve()
{
    int n,m;
    cin >> n >> m;
    vector<exam> tab(m);
    vector<int> ans(n + 5,0);
    for (int i = 0 ; i < m ; i++)
    {
        auto &it = tab[i];
        cin >> it.s >> it.d >> it.c;
        it.ix = i + 1;
        ans[it.d] = m + 1;
    }
    sort(tab.begin(),tab.end(),[&](exam &a,exam &b)
    {
        return (a.d < b.d);
    });
    for (auto it : tab)
    {
        const auto cnt = [&](int l,int r) -> int
        {
            int ret = 0;
            for (int i = l ; i <= r ; i++) ret += (ans[i] == 0);
            return ret;
        };        
        int avail = cnt(it.s,it.d - 1);
        if (avail >= it.c)
        {
            int cur = it.c;
            for (int i = it.s ; cur ; i++) if (ans[i] == 0)
            {
                --cur;
                ans[i] = it.ix;
            }
        }
        else
        {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 1 ; i <= n ; i++)
        cout << ans[i] << " ";
    cout << endl;
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