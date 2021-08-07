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

int pref[5010][5010];
string tab[5010];

void solve()
{
    int n,m;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) cin >> tab[i];
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = m ; j >= 1 ; j--)
        {
            if (tab[i][j - 1] == '1')
                pref[i][j] = pref[i][j + 1] + 1;
        }
    }
    // for (int i = 1 ; i <= n ; i++)
    // {
    //     for (int j = 1 ; j <= m ; j++)
    //     {
    //         cerr << pref[i][j] << " ";
    //     }
    //     cerr << endl;
    // }
    int ans = 0;
    for (int i = 1 ; i <= m ; i++)
    {
        vector<int> tmp;
        for (int j = 1 ; j <= n ; j++)
        {
            if (pref[j][i] > 0) tmp.push_back(pref[j][i]);
        }
        sort(tmp.begin(),tmp.end());
        for (int j = 0 ; j < tmp.size() ; j++)
        {
            ans = max(ans,((ll)tmp.size() - j) * tmp[j]);
        }
    }
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