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

int tree[400010];
int pos[100010];
int tab[100010];
int ans[100010];
int n;

void build(int node,int l,int r)
{
    if (l == r)
    {
        tree[node] = pos[l];
        return;
    }
    int mid = (l + r) >> 1;
    int child = node << 1;
    build(child,l,mid);
    build(child | 1,mid + 1,r);
    tree[node] = min(tree[child],tree[child | 1]);
}

int query(int node,int nodeL,int nodeR,int queryL,int queryR)
{
    if (queryL > nodeR || queryR < nodeL) return INF;
    if (queryL <= nodeL && nodeR <= queryR) return tree[node];
    int mid = (nodeL + nodeR) >> 1;
    int child = node << 1;
    return min(query(child,nodeL,mid,queryL,queryR),query(child | 1,mid + 1,nodeR,queryL,queryR));
}

void rec(int par,int cur,int l,int r)
{
    if (cur == -1) return;
    // cerr << cur << " " << l << " " << r << " " << par << endl;
    ans[pos[cur]] = par;
    //anak kiri
    int leftChild = -1;
    int leftChildPos = -1;
    if (l <= cur - 1) leftChildPos = query(1,1,n,l,cur - 1);
    if (leftChildPos > pos[cur]) leftChild = tab[leftChildPos];
    // cerr << leftChild << endl;
    rec(cur,leftChild,l,cur - 1);

    //anak kanan
    int rightChild = -1;
    int rightChildPos = -1;
    if (cur + 1 <= r) rightChildPos = query(1,1,n,cur + 1,r);
    if (rightChildPos > pos[cur]) rightChild = tab[rightChildPos];
    // cerr << rightChildPos << endl;
    rec(cur,rightChild,cur + 1,r);
}

void solve()
{
    cin >> n;
    vector<int> compress;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> tab[i];
        compress.push_back(tab[i]);
    }
    sort(compress.begin(),compress.end());
    compress.erase(unique(compress.begin(),compress.end()),compress.end());
    map<int,int> mp;
    for (int i = 0 ; i < n ; i++) mp[compress[i]] = i + 1;
    for (int i = 1 ; i <= n ; i++) 
    {
        tab[i] = mp[tab[i]];
        pos[tab[i]] = i;
    }
    build(1,1,n);
    rec(-1,tab[1],1,n);
    for (int i = 2 ; i <= n ; i++) 
    {
        int par = ans[i];
        --par;
        cout << compress[par] << " ";
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