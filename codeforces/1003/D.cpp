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
    int n,q;
    cin >> n >> q;
    vector<int> frek(35,0);
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        frek[__builtin_ctz(ta)]++;
    }
    while (q--)
    {
        int ta;
        cin >> ta;
        auto tmp = frek;
        int ans = 0;
        for (int i = 30 ; i >= 0 ; i--) if (ta & (1 << i))
        {
            int cur = (1 << i);
            bool can = 0;
            for (int j = i ; j >= 0 ; j--) if (cur >= (1 << j))
            {
                int need = cur / (1 << j);
                if (need <= tmp[j])
                {
                    ans += need;
                    tmp[j] -= need;
                    can = 1;
                    break;
                }
                else
                {
                    int take = tmp[j];
                    ans += take;
                    cur -= take * (1 << j);
                    tmp[j] -= take;
                }
            }   
            if (!can)
            {
                cout << -1 << endl;
                goto hell;
            }
        }
        cout << ans << endl;
        hell:;
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