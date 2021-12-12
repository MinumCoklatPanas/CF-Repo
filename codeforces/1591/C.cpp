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
    int n,k;
    cin >> n >> k;
    vector<int> pos,neg;
    for (int i = 0 ; i < n ; i++)
    {
        int ta;
        cin >> ta;
        if (ta > 0)
            pos.push_back(ta);
        else
            neg.push_back(-ta);
    }
    if (pos.size() == 0 && neg.size() == 0)
    {
        cout << 0 << endl;
        return;
    }
    sort(pos.begin(),pos.end());
    sort(neg.begin(),neg.end());
    const auto process = [&](vector<int> v) -> int
    {
        vector<int> dp(v.size());
        multiset<int> ms;
        for (int i = 0 ; i < min((int)v.size(),k) ; i++)
        {
            dp[i] = 2 * v[i];
            ms.insert(dp[i]);
        }
        for (int i = k ; i < v.size() ; i++)
        {
            // cerr <<"yo\n";
            if (i > k)
            {
                int hapus = dp[i - k - 1];
                ms.erase(ms.find(hapus));
            }
            int mn = *ms.begin();
            dp[i] = mn + 2 * v[i];
            ms.insert(dp[i]);
            // cerr << i << ": " << dp[i] << endl;
        }
        // return 0;
        return dp[v.size() - 1] - v[v.size() - 1];
    };
    int kanan = (pos.size() > 0 ? process(pos) : 0);
    // cerr << kanan << endl;
    int kiri = (neg.size() > 0 ? process(neg) : 0);
    int ans = kanan + kiri;
    int add;
    if (pos.size() == 0)
        add = 0;
    else
    if (neg.size() == 0)
        add = 0;
    else
        add = min(pos.back(),neg.back());
    ans += add;
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