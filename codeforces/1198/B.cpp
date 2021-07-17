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

struct op
{
    int tipe,p,x;
    op(){};
};


void solve()
{
    int n;
    cin >> n;
    vector<int> tab(n);
    for (auto &it : tab) cin >> it;
    int q;
    cin >> q;
    vector< op > qry(q);
    for (int i = 0 ; i < q ; i++)
    {
        cin >> qry[i].tipe;
        if (qry[i].tipe == 1)
        {
            cin >> qry[i].p >> qry[i].x;
            --qry[i].p;
        }
        else
            cin >> qry[i].x;
    }
    vector<bool> fixed(n,0);
    int curMin = -INF;
    for (int i = q - 1 ; i >= 0 ; i--)
    {
        if (qry[i].tipe == 1 && !fixed[qry[i].p])
        {
            // if (i == 0)
            //     cerr << tab[qry[i].p] << " " << qry[i].p << " " << curMin << endl;
            tab[qry[i].p] = max(curMin,qry[i].x);
            fixed[qry[i].p] = 1;
            // if (i == 0)
            //     cerr << tab[qry[i].p] << " " << qry[i].p << endl;
        }
        else
        if (qry[i].tipe == 2)
        {
            curMin = max(curMin,qry[i].x);
        }
        // cerr << i << endl;
        // for (auto it : tab)
        //     cerr << it << " ";
        // cerr << endl;
    }
    int lastMin = -INF;
    for (int i = q - 1 ; i >= 0 ; i--) if (qry[i].tipe == 2)
    {
        lastMin = max(lastMin,qry[i].x);
    }
    for (int i = 0 ; i < n ; i++) if (!fixed[i])
        tab[i] = max(tab[i],lastMin);
    for (auto it : tab)
        cout << it << " ";
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