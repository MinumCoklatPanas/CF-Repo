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
    vector<int> cnt(n + 5,0);
    for (auto &it : tab) cin >> it;
    tab.erase(unique(tab.begin(),tab.end()),tab.end());
    for (int i = 0 ; i < tab.size() ; i++)
    {
        if (i == 0)
        {
            cnt[tab[i]] += (tab[i + 1] != tab[i]);
        }
        else
        if (i == tab.size() - 1)
        {
            cnt[tab[i]] += (tab[i - 1] != tab[i]);
        }
        else
        {
            if (tab[i - 1] == tab[i + 1])
                cnt[tab[i]] += 2;
            else
                cnt[tab[i]]++;
        }
    }
    auto ans = max_element(cnt.begin(),cnt.end()) - cnt.begin();
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