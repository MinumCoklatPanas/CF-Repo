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
    int n,x;
    cin >> n >> x;
    vector<int> tab(n);
    for (auto &it : tab) cin >> it;
    int ans = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 0 ; j + 1 < n ; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                // for (auto it : tab)
                //     cerr << it << " ";
                // cerr << endl;
                // cerr << x << " x\n";
                // if (tab[0] < x)
                // {
                //     cout << -1 << endl;
                //     return;
                // }
                int ambil = -1;
                for (int k = j ; k >= 0 ; k--) if (tab[k] > x && (k == 0 || tab[k - 1] <= x))
                {
                    ambil = k;
                    break;
                }
                if (ambil == -1)
                {
                    cout << -1 << endl;
                    return;
                }
                ans += j - ambil + 1;
                int bef = tab[ambil];
                tab[ambil] = x;
                for (int k = ambil + 1 ; k <= j ; k++)
                {
                    int simpan = tab[k];
                    if (tab[k] == bef) --ans;
                    tab[k] = bef;
                    bef = simpan;
                }
                x = bef;
            }
        }
        // for (auto it : tab)
        //     cout << it << " ";
        // cout << endl;
    }
    assert(is_sorted(tab.begin(),tab.end()));
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