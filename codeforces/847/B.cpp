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

int tree[800010];
int pos[200010];
int tab[200010];
int n;

void upd(int node,int l,int r,int ix)
{
    if (l == r)
    {
        tree[node] = pos[l];
        return;
    }
    int mid = (l + r) >> 1;
    int child = node << 1;
    if (ix > mid)
        upd(child | 1,mid + 1,r,ix);
    else
        upd(child,l,mid,ix);
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

map<int,int> mp;

void upd(int ix,int k)
{
    pos[tab[ix]] = k;
    upd(1,1,n,tab[ix]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector< int > compress;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> tab[i];
        compress.push_back(tab[i]);
    }
    sort(compress.begin(),compress.end());
    for (int i = 0 ; i < n ; i++)
        mp[compress[i]] = i + 1;
    for (int i = 1 ; i <= n ; i++)
    {
        tab[i] = mp[tab[i]];
        pos[tab[i]] = i;
        upd(1,1,n,tab[i]);
    }
    vector< vector<int> > ans;
    while (tree[1] != INF)
    {
        vector<int> tmp;
        tmp.push_back(tab[tree[1]]);
        int cur = tab[tree[1]];
        upd(tree[1],INF);
        while (1)
        {
            int nxt = query(1,1,n,cur + 1,n);
            if (nxt == INF) break;
            tmp.push_back(tab[nxt]);
            cur = tab[nxt];
            upd(nxt,INF);
        }
        ans.push_back(tmp);
    }
    for (auto it : ans)
    {
        for (auto it2 : it)
            cout << compress[it2 - 1] << " ";
        cout << endl;
    }
    return 0;
}