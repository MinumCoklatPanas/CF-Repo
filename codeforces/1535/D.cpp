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
    int k;
    cin >> k;
    vector<char> tab((1 << k) + 5);
    vector<int> ans((1 << k) + 5);
    for (int i = (1 << k) - 1 ; i > 0 ; i--)
    {
        cin >> tab[i];
    }
    for (int i = (1 << k) - 1 ; i > (1 << k) - 1 - (1 << (k - 1)) ; i--)
    {
        ans[i] = (tab[i] == '?' ? 2 : 1);
        // cerr << i << " " << ans[i] << endl;
    }
    for (int i = (1 << k) - 1 - (1 << (k - 1)) ; i > 0 ; i--)
    {
        if (tab[i] == '1')
            ans[i] = ans[i * 2];
        else
        if (tab[i] == '0')
            ans[i] = ans[i * 2 + 1];
        else
        {
            ans[i] = ans[i * 2] + ans[i * 2 + 1];
        }
        // cerr << i << " " << ans[i] << " " << tab[i] << " " << ans[i * 2] << " " << ans[i * 2 + 1] << endl;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int p;
        char c;
        cin >> p >> c;
        p = (1 << k) - p;
        tab[p] = c;
        int i = p;
        if (i >= (1 << (k - 1)))
        {
            ans[i] = (tab[i] == '?' ? 2 : 1);
            i /= 2;
        }
        while (i)
        {
            if (tab[i] == '1')
                ans[i] = ans[i * 2];
            else
            if (tab[i] == '0')
                ans[i] = ans[i * 2 + 1];
            else
                ans[i] = ans[i * 2] + ans[i * 2 + 1];
            // cerr << i << " " << ans[i] << " " << tab[i] << " " << ans[i * 2] << " " << ans[i * 2 + 1] << endl;
            i /= 2;
            // cerr << i << " after\n";
        }
        cout << ans[1] << endl;
        // cerr << endl;
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