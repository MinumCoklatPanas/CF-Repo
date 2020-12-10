#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
const int blk = 300;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int cei(int x,int y)
{
    return (x / y) + (x % y != 0);
}

struct mo
{
    int l,r,k,ix;

    mo(){};

    mo(int _l, int _r, int _k,int _ix)
    {
        l = _l;
        r = _r;
        k = _k;
        ix = _ix;
    }

    bool operator< (mo& other) const 
    {
        int kiri = cei(l,blk);
        int kanan = cei(other.l,blk);
        if (kiri == kanan)
            return (r < other.r);
        return (kiri < kanan);
    }   
};

int tree[400010];
int tab[100010];

void build(int n)
{
    for (int i = n - 1; i > 0; --i) tree[i] = __gcd(tree[i<<1],tree[i<<1|1]);
}

int query(int l,int r,int n)
{
    int ret = tab[l];
    for (l += n, r += n ; l < r ; l >>= 1, r >>= 1)
    {
        if (l & 1) ret = __gcd(ret,tree[l++]);
        if (r & 1) ret = __gcd(ret,tree[--r]);
    }
    return ret;
}

mo queries[100010];
int ans[100010];
unordered_map<int,int> cnt;

void add(int ix)
{
    if (ix < 0) return;
    ++cnt[tab[ix]];
}

void erase(int ix)
{
    if (ix < 0) return;
    --cnt[tab[ix]];
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int n;
    // cin >> n;
    scanf("%d",&n);
    for (int i = 0 ; i < n ; i++) 
    {
        scanf("%d",&tab[i]);
        tree[i + n] = tab[i];
    }
    build(n);
    int q;
    // cin >> q;
    scanf("%d",&q);
    for (int i = 1 ; i <= q ; i++)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        --l; --r;
        // cin >> l >> r;
        int k = query(l,r + 1,n);
        assert(k != -1);
        queries[i] = mo(l,r,k,i);
        // cout << l << " " << r << " " << k << endl;
    }
    sort(queries + 1,queries + q + 1);
    int curL = 0;
    int curR = 0;
    // cout << "yo\n";
    // return 0;
    for (int i = 1 ; i <= q ; i++)
    {
        int l = queries[i].l;
        int r = queries[i].r;
        while (curL > l)
        {
            add(curL - 1);
            --curL;
        }
        while (curR <= r)
        {
            add(curR);
            ++curR;
        }
        while (curL < l)
        {
            erase(curL);
            ++curL;
        }
        while (curR > r + 1)
        {
            erase(curR - 1);
            --curR;
        }
        // cout << queries[i].l << " " << queries[i].r < " " << queries[i].k << " " << queries[i].ix << endl;
        // // cout << queries[i].ix << endl;
        // cout << "yo\n";
        // return 0;
        ans[queries[i].ix] = (r - l + 1) - cnt[queries[i].k]; 
    }
    for (int i = 1 ; i <= q ; i++)
        // cout << ans[i] << endl;
        printf("%d\n",ans[i]);
    return 0;
}