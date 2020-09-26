#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
#define int long long
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 998244353;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

int mul(int x,int y)
{
    return ((x % MOD) * (y % MOD)) % MOD;
}

int add(int x,int y)
{
    return ((x % MOD) + (y % MOD)) % MOD;
}

int sub(int x,int y)
{
    int ret = ((x % MOD) - (y % MOD)) % MOD;
    if (ret < 0)
        ret += MOD;
    return ret;
}

int modpow(int x,int y)
{
    if (!y) return 1;
    int z = modpow(x,y / 2);
    z = mul(z,z);
    if (y & 1) z = mul(z,x);
    return z;
}

int inv(int x)
{
    return modpow(x,MOD - 2);
}

int bagi(int x,int y)
{
    return mul(x,inv(y));
}

int n,q;

int tree[800010];
int pengali[800010];
int lazy[800010];
int pan[800010];

void build(int node,int l,int r)
{
    if (l == r)
    {
        pengali[node] = pan[n - l];
        // cout << l << " " << n - l + 1 << " " << pan[n - l + 1] << endl;
        // cout << l << " " << r << " " << pengali[node] << endl;
        tree[node] = pengali[node];
        return;
    }
    int mid = (l + r) >> 1;
    int child = node << 1;
    build(child,l,mid);
    build(child | 1,mid + 1,r);
    tree[node] = add(tree[child],tree[child | 1]);
    pengali[node] = add(pengali[child],pengali[child | 1]);
}

void upd(int node,int val)
{
    if (val == 0) return;
    lazy[node] = val;
    tree[node] = mul(val,pengali[node]);
    return;
}

void propagate(int node)
{
    upd(node * 2,lazy[node]);
    upd(node * 2 + 1,lazy[node]);
    lazy[node] = 0;
}

void rangeUpdate(int node,int nodeL,int nodeR,int queryL,int queryR,int val)
{
    if (queryL > nodeR || queryR < nodeL) return;
    if (queryL <= nodeL && nodeR <= queryR)
    {
        upd(node,val);
        return;
    }
    propagate(node);
    int mid = (nodeL + nodeR) >> 1;
    int child = node << 1;
    rangeUpdate(child,nodeL,mid,queryL,queryR,val);
    rangeUpdate(child | 1,mid + 1,nodeR,queryL,queryR,val);
    tree[node] = add(tree[child],tree[child | 1]);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pan[0] = 1;
    for (int i = 1 ; i <= 200000 ; i++)
        pan[i] = mul(pan[i - 1],10ll);
    cin >> n >> q;
    build(1,1,n);
    while (q--)
    {
        int l,r,v;
        cin >> l >> r >> v;
        rangeUpdate(1,1,n,l,r,v);
        cout << tree[1] << endl;
    }
    return 0;
}
