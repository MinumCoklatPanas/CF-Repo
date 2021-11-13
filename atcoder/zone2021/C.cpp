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

int tab[3010][5];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
        for (int j = 0 ; j < 5 ; j++)
            cin >> tab[i][j];
    const auto cek = [&](int x) -> bool
    {
        set<int> st;
        for (int i = 1 ; i <= n ; i++)
        {
            int mask = 0;
            for (int j = 0 ; j < 5 ; j++) if (tab[i][j] >= x)
                mask |= (1 << j);
            st.insert(mask);
        }
        for (auto a : st)
            for (auto b : st)
                for (auto c : st)
                {
                    if ((a | b | c) == 31) return true;
                }
        return 0;
    };
    int l = 1;
    int r = INF;
    while (r - l > 1)
    {
        int mid = (l + r) >> 1;
        if (cek(mid))
            l = mid;
        else
            r = mid;
    }
    if (cek(r))
        cout << r << endl;
    else
        cout << l << endl;
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