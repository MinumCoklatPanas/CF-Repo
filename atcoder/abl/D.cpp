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

int tree[1200010];
int tab[300010];

void upd(int node,int l,int r,int val,int ix)
{
    if (l == r)
    {
        tree[node] = val;
        return;
    }
    int mid = (l + r) >> 1;
    int child = node << 1;
    if (ix > mid)
        upd(child | 1,mid + 1,r,val,ix);
    else
        upd(child,l,mid,val,ix);
    tree[node] = max(tree[child],tree[child | 1]);
}

int rangeQuery(int node,int nodeL,int nodeR,int queryL,int queryR)
{
    if (queryL > nodeR || queryR < nodeL) return -INF;
    if (queryL <= nodeL && nodeR <= queryR) return tree[node];
    int mid = (nodeL + nodeR) >> 1;
    int child = node << 1;
    return max(rangeQuery(child,nodeL,mid,queryL,queryR),rangeQuery(child | 1,mid + 1,nodeR,queryL,queryR));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    int ans = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        int l = max(ta - k,1);
        int r = min(ta + k,300000);
        int tmp = rangeQuery(1,1,300000,l,r) + 1;
        // cout << ta << " " << l << " " << r << " " << tmp << endl;
        ans = max(ans,tmp);
        upd(1,1,300000,tmp,ta);
    }
    cout << ans << endl;
    return 0;
}