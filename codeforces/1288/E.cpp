#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
// #define int long long
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define MULTI_TC 0

typedef tree<int, null_type, less<int>,
rb_tree_tag,tree_order_statistics_node_update> ordered_set;

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

struct SegTree
{
    int n;
    vector<vector<int>> Tree;
    vector<int> tab;
    SegTree(){}
    SegTree(int _n)
    {
        n = _n;
        Tree.resize(4 * n + 10);
        tab.resize(n + 5,-1);
        Build(1,1,n);
    }
    
    void MergeNode(vector<int> &a,vector<int> &b,vector<int> &c)
    {
        c.clear();
        merge(a.begin(),a.end(),b.begin(),b.end(),back_inserter(c));
    }

    void Build(int node,int nodeL,int nodeR)
    {
        if (nodeL == nodeR)
        {   
            Tree[node].push_back(tab[nodeL]);
            return;
        }
        int mid = (nodeL + nodeR) >> 1;
        int child = node << 1;
        Build(child,nodeL,mid);
        Build(child | 1,mid + 1,nodeR);
        MergeNode(Tree[child],Tree[child | 1],Tree[node]);
    }

    int Query(int node,int nodeL,int nodeR,int queryL,int queryR,int k)
    {
        if (queryL > nodeR || queryR < nodeL) return 0;
        if (queryL <= nodeL && nodeR <= queryR)
        {
            // cerr << Tree[node].size() << endl;
            // for (auto it : Tree[node])
            //     cerr << it << " ";
            // cerr << endl;
            int cnt = upper_bound(Tree[node].begin(),Tree[node].end(),k) - Tree[node].begin();
            // cerr << cnt << endl;
            return Tree[node].size() - cnt;
        }
        int mid = (queryL + queryR) >> 1;
        int child = node << 1;
        return Query(child,nodeL,mid,queryL,queryR,k) + Query(child | 1,mid + 1,nodeR,queryL,queryR,k);
    }

    void Update(int node,int nodeL,int nodeR,int ix,int k)
    {
        if (nodeL == nodeR)
        {
            Tree[node][0] = k;
            return;
        }
        int mid = (nodeL + nodeR) >> 1;
        int child = node << 1;
        if (ix > mid)
            Update(child | 1,mid + 1,nodeR,ix,k);
        else
            Update(child,nodeL,mid,ix,k);
        MergeNode(Tree[child],Tree[child | 1],Tree[node]);        
    }

    void Update(int ix,int k)
    {
        tab[ix] = k;
        Update(1,1,n,ix,k);
    }
};


void solve()
{
    int n,m;
    scanf("%d %d",&n,&m);
    // cin >> n >> m;
    vector<int> tab(m);
    for (auto &it : tab) scanf("%d",&it);
    vector<int> mn(n + 5),mx(n + 5);
    for (int i = 1 ; i <= n ; i++) mn[i] = mx[i] = i;
    vector<int> lastOccurence(n + 5,-1);
    vector<int> lastPos(n + 5,-1);
    for (int i = 1 ; i <= n ; i++) lastPos[i] = i;
    ordered_set nums,pos;
    for (int i = 0 ; i < m ; i++)
    {
        int curPos = tab[i];
        mn[tab[i]] = 1;
        if (lastOccurence[tab[i]] == -1)
        {
            int more = nums.size() - nums.order_of_key(tab[i]);
            curPos += more;
        }
        else
        {
            curPos = 1;
            int more = pos.size() - pos.order_of_key(lastOccurence[tab[i]] + 1);
            curPos += more;
        }
        nums.insert(tab[i]);
        mn[tab[i]] = min(mn[tab[i]],curPos);
        mx[tab[i]] = max(mx[tab[i]],curPos);
        if (lastOccurence[tab[i]] != -1)
            pos.erase(lastOccurence[tab[i]]);
        lastOccurence[tab[i]] = i;
        pos.insert(lastOccurence[tab[i]]);
        lastPos[tab[i]] = 1;
    }    
    // cerr << "DEBUG\n";
    // cerr << "==============================\n";
    // ST.Query(1,1,n,1,n,0);
    // cerr << "==============================\n";
    // return;
    for (int i = 1 ; i <= n ; i++) 
    {
        if (lastOccurence[i] == -1)
        {
            mx[i] += nums.size() - nums.order_of_key(i);
        }
        else
        {
            int curPos = lastPos[i];
            // if (i == 3)
            //     cerr << curPos << endl;
            int more = pos.size() - pos.order_of_key(lastOccurence[i] + 1);
            // if (i == 3)
            // {
            //     for (auto it : pos)
            //         cerr << it << endl;
            // }
            curPos += more;
            mx[i] = max(mx[i],curPos);
        }
    }
    for (int i = 1 ; i <= n ; i++)
    {
        printf("%d %d\n",mn[i],mx[i]);
    }
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