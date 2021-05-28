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

int tab[100010];
int tree[200010];
int n,m;

int mul(int x,int y)
{
    return ((x % m) * (y % m)) % m;
}

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) tree[i] = mul(tree[i<<1],tree[i<<1|1]);
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 1;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = mul(res,tree[l++]);
    if (r&1) res = mul(res,tree[--r]);
  }
  return res;
}


void solve()
{
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> tree[i + n];
        // cerr << i + n << " " << tree[i + n] << endl;
        tree[i + n] %= m;
    }
    build();
    // cerr << query(0,1) << endl;
    // return;
    int ans = 0;
    for (int i = 0 ; i < n ; i++)
    {
        int l = i;
        int r = n - 1;
        while (r - l > 1)
        {
            int mid = (l + r) >> 1;
            int ret = query(i,mid + 1);
            if (ret == 0)
                r = mid;
            else
                l = mid + 1;
        }
        // cerr << i << " " << l << " " << r << endl;
        if (query(i,l + 1) == 0)
            ans += n - l;
        else
        if (query(i,r + 1) == 0)
            ans += n - r;
    }
    cout << ans << endl;
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