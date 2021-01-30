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

struct BIT
{
    vector<int> tree;

    BIT()
    {
        tree.resize(300010,0);
    };

    void upd(int x,int val)
    {
        // cout << x << endl;
        for ( ; x <= 300000 ; x += (x & -x))
            tree[x] += val;
    }

    int query(int x)
    {
        int ret = 0;
        for ( ; x ; x -= (x & -x))
            ret += tree[x];
        return ret;
    }

    int get(int l,int r)
    {
        return query(r) - query(l - 1);
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    BIT kiri,kanan;
    // cout << "yo\n";
    // return 0;
    int n;
    cin >> n;
    vector<int> tab(n);
    int curInversion = 0;
    for (auto &it : tab) 
    {
        cin >> it;
        ++it;
        kanan.upd(it,1);
        curInversion += kanan.get(it + 1,300000);
        // return 0;
    }
    cout << curInversion << endl;
    for (int i = 0 ; i < n - 1 ; i++)
    {
        kanan.upd(tab[i],-1);
        kiri.upd(tab[i],1);
        int nambah = n - tab[i];
        int kurang = kiri.query(tab[i] - 1) + kanan.query(tab[i] - 1);
        curInversion += nambah;
        curInversion -= kurang;
        cout << curInversion << endl;
    }
    return 0;
}