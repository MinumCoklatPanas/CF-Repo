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
    int n,k;
    cin >> n >> k;
    vector<int> tab(n);
    for (auto &it : tab) cin >> it;
    int mx = *max_element(tab.begin(),tab.end());
    int mn = *min_element(tab.begin(),tab.end());
    if (k == 1)
        cout << mn << endl;
    else
    if (tab[0] == mx || tab[n - 1] == mx || k > 2)
        cout << mx << endl;
    else
    {
        vector<int> prefMin(n),sufMin(n);
        prefMin[0] = tab[0];
        for (int i = 1 ; i < n ; i++)
            prefMin[i] = min(prefMin[i - 1],tab[i]);

        sufMin[n - 1] = tab[n - 1];
        for (int i = n - 2 ; i >= 0 ; i--)
            sufMin[i] = min(sufMin[i + 1],tab[i]);
        int ans = -INFF;
        for (int i = 0 ; i + 1 < n ; i++)
        {
            int kiri = prefMin[i];
            int kanan = sufMin[i + 1];
            // cerr << i << " " << kiri << " " << kanan << endl;
            ans = max(ans,max(kiri,kanan));
        }
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