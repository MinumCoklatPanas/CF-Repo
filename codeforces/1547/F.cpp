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
#define MULTI_TC 1

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

int tab[400010];
int tree[1600010];

void build(int node,int l,int r)
{
    if (l == r)
    {
        tree[node] = tab[l];
        return;
    }
    int mid = (l + r) >> 1;
    int child = node << 1;
    build(child,l,mid);
    build(child | 1,mid + 1,r);
    tree[node] = __gcd(tree[child],tree[child | 1]);
}

int query(int node,int nodeL,int nodeR,int queryL,int queryR)
{
    if (queryL > nodeR || queryR < nodeL) return 0;
    if (queryL <= nodeL && nodeR <= queryR) return tree[node];
    int mid = (nodeL + nodeR) >> 1;
    int child = node << 1;
    return __gcd(query(child,nodeL,mid,queryL,queryR),query(child | 1,mid + 1,nodeR,queryL,queryR));
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> tab[i];
    for (int i = n + 1 ; i <= 2 * n ; i++) tab[i] = tab[i - n];
    build(1,1,2 * n);
    // int mx = 0;
    int allGCD = 0;
    for (int i = 1 ; i <= n ; i++) allGCD = __gcd(allGCD,tab[i]);

    const auto can = [&](int l,int r) -> int
    {
        return (query(1,1,2 * n,l,r) == allGCD);
    };

    int mx = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        int l = i;
        int r = n + i - 1;
        while (r - l > 1)
        {
            int mid = (l + r) >> 1;
            if (can(i,mid))
                r = mid;
            else
                l = mid + 1;
        }
        int ambil;
        if (can(i,l))
            ambil = l;
        else
            ambil = r;
        int len = ambil - i + 1;
        mx = max(mx,len);
    }
    cout << mx - 1 << endl;
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