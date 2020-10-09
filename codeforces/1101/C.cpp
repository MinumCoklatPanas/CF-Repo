#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

int par[100010];
int n,numset;

int finds(int x)
{
    return (par[x] == x ? x : par[x] = finds(par[x]));
}

void joins(int x,int y)
{
    int px = finds(x);
    int py = finds(y);
    if (px == py) return;
    par[px] = py;
    --numset;
}

vector<int> elements[100010];
struct node
{
    int l,r,ix;

    node(){};

    node(int _l,int _r,int _ix)
    {
        l = _l;
        r = _r;
        ix = _ix;
    }

    bool operator< (node& other) const
    {
        return make_pair(make_pair(l,r),ix) < make_pair(make_pair(other.l,other.r),other.ix);
    }
};

int ans[100010];
node tab[100010];

void solve()
{
    cin >> n;
    numset = n;
    for (int i = 1 ; i <= n ; i++) par[i] = i,elements[i].clear(),ans[i] = -1;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> tab[i].l >> tab[i].r;
        tab[i].ix = i;
    }
    sort(tab + 1,tab + n + 1);
    int curL = tab[1].l;
    int curR = tab[1].r;
    int curPar = tab[1].ix;
    for (int i = 2 ; i <= n ; i++)
    {
        if (tab[i].l <= curR)
        {
            joins(tab[i].ix,curPar);
            curR = max(curR,tab[i].r);
        }
        else
        {
            curL = tab[i].l;
            curR = tab[i].r;
            curPar = tab[i].ix;
        }
    }
    if (numset == 1)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 1 ; i <= n ; i++)
        elements[finds(i)].push_back(i);
    int cur = 1;
    for (int i = 1 ; i <= n ; i++)
    {
        bool ada = 0;
        for (auto it : elements[i])
        {
            ada = 1;
            ans[it] = cur;
        }
        if (ada && cur == 1)
            ++cur; 
    }
    for (int i = 1 ; i <= n ; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}