// time-limit: 2000
// problem-url: https://codeforces.com/contest/1059/problem/B
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
    vector<string> tab(n);
    string isi = "";
    for (int i = 0 ; i < m ; i++) isi += '.';
    vector<string> ans(n,isi);
    for (auto &it : tab) cin >> it;
    // for (auto it : tab)
    //     cout << it << endl;
    // cout << endl;
    int d[3] = {-1,0,1};
    for (int i =  1 ; i < n ; i++)
    {
        for (int j = 1 ; j < m ; j++)
        {
            int cntValid = 0;
            int cntInked = 0;
            for (int k = 0 ; k < 3 ; k++)
                for (int l = 0 ; l < 3 ; l++)
                {
                    if (d[k] == 0 && d[l] == 0) continue;
                    int ii = i + d[k];
                    int jj = j + d[l];
                    const auto between = [&](int a,int b,int c) -> bool
                    {
                        return (a <= c && c < b);
                    };
                    // cerr << ii << " " << jj << endl;/
                    if ((between(0,n,ii) && between(0,m,jj)))
                    {
                        cntValid++;
                        cntInked += (tab[ii][jj] == '#');
                    }
                }
            if (cntValid == 8 && cntInked == 8)
            {
                // cerr << i << " " << j << endl;
                for (int k = 0 ; k < 3 ; k++)
                    for (int l = 0 ; l < 3 ; l++)
                    {
                        if (d[k] == 0 && d[l] == 0) continue;
                        int ii = i + d[k];
                        int jj = j + d[l];
                        const auto between = [&](int a,int b,int c) -> bool
                        {
                            return (a <= c && c < b);
                        };
                        // cout << ii << " " << jj << endl;
                        ans[ii][jj] = '#';
                    }
            }
        }
    }
    if (ans == tab)
        cout << "YES\n";
    else
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