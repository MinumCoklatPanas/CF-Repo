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
    int n,m;
    cin >> n >> m;
    vector<int> tab(n);
    for (auto &it : tab) cin >> it;
    vector<pair<int,int>> range(m);
    for (auto &it : range) 
    {
        cin >> it.first >> it.second;    
        --it.first; --it.second;
    }
    int ans = 0;
    vector<int> ambil;
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < n ; j++)
        {
            vector<int> tmp;
            int curDiff = tab[j] - tab[i];
            for (int k = 0 ; k < m ; k++) if (range[k].first <= i && i <= range[k].second)
            {
                if (j < range[k].first || j > range[k].second) ++curDiff;
                tmp.push_back(k + 1);
            }
            if (curDiff > ans)
            {
                ans = curDiff;
                ambil = tmp;
            }
        }
    cout << ans << endl;
    cout << ambil.size() << endl;
    for (auto it : ambil) cout << it << " ";
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