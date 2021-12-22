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
    int n,m;
    cin >> m >> n;
    vector<vector<int>> tab(m,vector<int>(n));
    for (auto &it : tab)
        for (auto &it2 : it)
            cin >> it2;
    const auto cek = [&](int x) -> bool
    {
        bool ada = 0;
        for (int i = 0 ; i < m ; i++)
        {
            int cnt = 0;
            for (int j = 0 ; j < n ; j++)
            {
                cnt += (tab[i][j] >= x);
            }
            ada |= (cnt > 1);
        }
        bool valid = 1;
        for (int j = 0 ; j < n ; j++)
        {
            bool hehe = 0;
            for (int i = 0 ; i < m ; i++)
            {
                hehe |= (tab[i][j] >= x);
                // cerr << tab[i][j] << " ";
            }
            // cerr << " " << hehe << endl;
            valid &= hehe;
        }
        // cerr << ada << " " << valid << endl;
        return (ada && valid);
    };
    // cek(2);
    // return;
    int l = 1;
    int r = INF;
    while (r - l > 1)
    {
        int mid = (l + r) >> 1;
        if (cek(mid))
            l = mid;
        else
            r = mid - 1;
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