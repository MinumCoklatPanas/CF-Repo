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
    int n;
    cin >> n;
    vector<vector<int>> tab(n);    
    vector<int> a(n),b(n);
    for (auto &it : a) 
    {
        cin >> it;
        --it;
    }
    int sum = 0;
    for (auto &it : b)
    {
        cin >> it;
        sum += it;
    }
    for (int i = 0 ; i < n ; i++)
    {
        tab[a[i]].push_back(b[i]);
    }
    for (int i = 0 ; i < n ; i++) sort(tab[i].begin(),tab[i].end());
    vector<int> ans(n + 5,0);
    vector<vector<int>> pref(n);
    for (int i = 0 ; i < n ; i++)
    {
        pref[i].resize(tab[i].size() + 5,0);
        for (int j = 1 ; j <= tab[i].size() ; j++)
        {
            pref[i][j] = pref[i][j - 1] + tab[i][j - 1];
            // cerr << i << " " << j << " " << pref[i][j] << endl;
        }
    }
    // return;
    const auto add = [&](int l,int r,int v) -> void
    {
        if (l > r) return;
        ans[l] += v;
        ans[r + 1] -= v;
    };
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 1 ; j <= tab[i].size() ; j++)
        {
            int rem = tab[i].size() % j;
            // cerr << i << " " << j << " " << rem << endl;
            int notTaken = pref[i][rem];
            add(j,j,notTaken);
        }
        add(tab[i].size() + 1,n,pref[i][tab[i].size()]);
    }
    for (int i = 1 ; i <= n ; i++) ans[i] += ans[i - 1];
    for (int i = 1 ; i <= n ; i++)
    {
        cout << sum - ans[i] << " ";
    }
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