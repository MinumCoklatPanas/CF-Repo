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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int readInt()
{
    bool minus = false;
    int result = 0;
    char ch;
    ch = _getchar_nolock();
    while (true)
    {
            if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = _getchar_nolock();
    }
    if (ch == '-') minus = true;
    else result = ch-'0';
    while (true)
    {
        ch = _getchar_nolock();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

int tab[500010];
int tree[1000010];

void build(int n)
{
    for (int i = n - 1 ; i > 0 ; i--) tree[i] = __gcd(tree[i << 1],tree[i << 1|1]);
}

void upd(int ix,int val,int n)
{
    for (tree[ix += n] = val ; ix > 1 ; ix >>= 1) tree[ix >> 1] = __gcd(tree[ix],tree[ix ^ 1]);
}

int query(int l,int r,int n)
{
    ++r;
    int res = tab[l];
    for (l += n, r += n ; l < r ; l >>= 1, r >>= 1)
    {
        if (l & 1) res = __gcd(res,tree[l++]);
        if (r & 1) res = __gcd(res,tree[--r]);
    }
    return res;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int n = readInt();
    // cin >> n;
    // scanf("%d",&n);
    for (int i = 0 ; i < n ; i++) tab[i] = readInt(),tree[i + n] = tab[i];
    build(n);
    int q = readInt();
    while (q--)
    {
        int ask = readInt();
        if (ask == 2)
        {
            int ix = readInt(),val = readInt();
            --ix;
            tab[ix] = val;
            upd(ix,val,n);
        }
        else
        {
            int l = readInt(),r = readInt(),x = readInt();
            --l; --r;
            // cout << ask << " " << l << " " << r << " " << x << endl;
            if (l == r)
            {
                puts("YES");
                continue;
            }
            int curGcd = query(l,r,n);
            // cout << curGcd << endl;
            if (curGcd % x == 0)
                puts("YES");
            else
            {
                int lo = l;
                int hi = r;
                while (hi - lo > 1)
                {
                    int mid = (hi + lo) >> 1;
                    int tmp = query(l,mid,n);
                    if (tmp % x == 0)
                        lo = mid + 1;
                    else
                        hi = mid;
                }
                int transisi;
                if (query(l,lo,n) % x != 0)
                    transisi = lo;
                else
                    transisi = hi;
                if (transisi + 1 > r)
                {
                    puts("YES");
                    continue;
                }
                if (query(transisi + 1,r,n) % x == 0)
                    puts("YES");
                else
                    puts("NO");
            }
        }
    }
    return 0;
}