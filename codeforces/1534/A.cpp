// time-limit: 1500
// problem-url: https://codeforces.com/contest/1534/problem/A
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
    cin  >> n >> m;
    vector< string > tab(n);
    for (auto &it : tab) cin >> it;
    vector< string > ans(n);
    //W R
    pair<char,char> tmp = {'W','R'};
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < m ; j++)
        {
            if (j % 2 == 0)
                ans[i] += tmp.first;
            else
                ans[i] += tmp.second;
        }
        swap(tmp.first,tmp.second);
    }
    bool can = 1;
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < m ; j++) if (tab[i][j] != '.')
        {
            if (tab[i][j] != ans[i][j])
            {
                // cerr << i << " " << j << endl;
                can = 0;
            }
        }
    }
    if (can)
    {
        cout << "YES\n";
        for (auto it : ans) cout << it << endl;
        return;
    }
    for (auto &it : ans) it = "";
    tmp = {'R','W'};
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < m ; j++)
        {
            if (j % 2 == 0)
                ans[i] += tmp.first;
            else
                ans[i] += tmp.second;
        }
        swap(tmp.first,tmp.second);
    }
    // for (auto it : ans) cout << it << endl;
    can = 1;
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < m ; j++) if (tab[i][j] != '.')
        {
            if (tab[i][j] != ans[i][j])
            {
                can = 0;
            }
        }
    }
    if (can)
    {
        cout << "YES\n";
        for (auto it : ans) cout << it << endl;
        return;
    }
    cout << "NO\n";
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