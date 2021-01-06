#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
#define int long long
#define w first
#define h second
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int tree[800010];
pair<int,int> tab[200010];
pair< pair<int,int>,int > sorted[200010];
int ans[200010];

void build(int node,int l,int r)
{
    if (l == r)
    {
        tree[node] = sorted[l].second;
        return;
    }
    int mid = (l + r) >> 1;
    int child = node << 1;
    build(child,l,mid);
    build(child | 1,mid + 1,r);
    if (tab[tree[child]].h < tab[tree[child | 1]].h)
        tree[node] = tree[child];
    else
        tree[node] = tree[child | 1];
}

int query(int node,int nodeL,int nodeR,int queryL,int queryR)
{
    if (queryL > nodeR || queryR < nodeL) return -1;
    if (queryL <= nodeL && nodeR <= queryR) return tree[node];
    int mid = (nodeL + nodeR) >> 1;
    int child = node << 1;
    int kiri = query(child,nodeL,mid,queryL,queryR);
    int kanan = query(child | 1,mid + 1,nodeR,queryL,queryR);
    if (kiri == -1) return kanan;
    if (kanan == -1) return kiri;
    if (tab[kiri].h < tab[kanan].h) return kiri;
    else return kanan;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> tab[i].second >> tab[i].first;
        sorted[i] = {tab[i],i};
        ans[i] = -1;
    }
    vector<int> wVals;
    sort(sorted + 1,sorted + n + 1);
    // for (int i = 1 ; i <= n ; i++)
    //     cerr << sorted[i].first.first << " " << sorted[i].first.second << endl;
    // cerr << endl;
    // cerr << sorted[3].first.h << endl;
    for (int i = 1 ; i <= n ; i++)
        wVals.push_back(sorted[i].first.w);
    build(1,1,n);
    for (int i = 1 ; i <= n ; i++)
    {
        int ix = lower_bound(wVals.begin(),wVals.end(),tab[i].w) - wVals.begin() - 1;
        // cerr << i << " " << ix << " ";
        if (ix > -1)
        {
            ++ix;
            if (sorted[ix].first.w < tab[i].w)
            {
                int mn = query(1,1,n,1,ix);
                // if (i == 1) cerr << tab[mn].h << " ix\n";
                if (tab[mn].h < tab[i].h)
                {
                    cout << mn << " ";
                    continue;
                }
            }
        }
        ix = lower_bound(wVals.begin(),wVals.end(),tab[i].h) - wVals.begin() - 1;
        // cerr << ix << endl;
        if (ix > -1)
        {
            ++ix;
            if (sorted[ix].first.w < tab[i].h)
            {
                int mn = query(1,1,n,1,ix);
                if (tab[mn].h < tab[i].w)
                {
                    cout << mn << " ";
                    continue;
                }
            }
        }
        cout << -1 << " ";
    }
    cout << endl;
}

signed main()
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