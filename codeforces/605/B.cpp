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

struct dt
{
    int weight,taken,index;
    dt(){};

    bool operator< (dt &other) const
    {
        if (weight == other.weight)
        {
            if (taken == other.taken)
                return (index < other.index);
            else
                return (taken > other.taken);
        }
        else
            return (weight < other.weight);
    }
};


void solve()
{
    int n,m;
    cin >> n >> m;
    vector< dt > tab(m);
    for (int i = 0 ; i < m ; i++)
    {
        cin >> tab[i].weight >> tab[i].taken;
        tab[i].index = i;
    }
    sort(tab.begin(),tab.end());
    if (tab[0].taken == 0)
    {
        cout << -1 << endl;
        return;
    }
    if (n == 2)
    {
        cout << " 1 2\n";
        return;
    }
    if (tab[1].taken == 0)
    {
        cout << -1 << endl;
        return;
    }
    vector< pair<int,int> > ans(m);
    ans[tab[0].index] = {1,2};
    int sz = 2;
    int sambung = 3;
    set<pair<int,int>> auxEdge;
    int used = m - 1;
    for (int i = 1 ; i < m ; i++)
    {
        int w = tab[i].weight;
        int stat = tab[i].taken;
        int ix = tab[i].index;
        if (stat)
        {
            ans[ix] = {sambung - 1,sambung};
            ++sambung;
            ++sz;
            --used;
            for (int j = 1 ; j + 1 < sz && used > 0 ; j++,used--)
                auxEdge.insert({j,sz});
        }
        else
        {
            int maxUse = (sz * (sz - 1)) / 2;
            if (i + 1 > maxUse)
            {
                assert(auxEdge.empty());
                cout << -1 << endl;
                return;
            }
            ans[ix] = *auxEdge.begin();
            auxEdge.erase(auxEdge.begin());
        }
    }
    for (auto it : ans)
        cout << it.first << " " << it.second << endl;
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