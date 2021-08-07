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

struct query
{
    int tipe,l,r;

    query(){}
    query(int _tipe,int _l,int _r)
    {
        tipe = _tipe;
        l = _l;
        r = _r;
    }
};


void solve()
{
    int n,q,m;
    cin >> n >> q >> m;
    vector<int> tab(n);
    for (auto &it : tab) cin >> it;
    vector<query> qry(q);
    for (auto &it : qry) cin >> it.tipe >> it.l >> it.r;
    vector<int> special(m);
    for (auto &it : special)
    {
        --it;
        cin >> it;
    }
    for (auto &it : special)
    {
        for (int i = q - 1 ; i >= 0 ; i--) if (qry[i].l <= it && it <= qry[i].r)
        {
            if (qry[i].tipe == 1)
            {
                if (it != qry[i].l)
                    it = it - 1;
                else
                    it = qry[i].r;
            }
            else
                it = qry[i].r - it + qry[i].l;
        }   
    }
    for (auto it : special)
        cout << tab[it - 1] << " ";
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