#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
#define int long long
const int INF = 1e9;
const ll INFF = 4e18;
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

struct segtree
{
    vector<int> tree;
    int n;
    segtree(){}
    segtree(int _n,vector<int> &tab)
    {
        n = _n;
        tree.resize(2ll * n + 5,-INFF);
        for (int i = 0 ; i < n ; i++)
        {
            tree[n + i] = tab[i];
            // cerr << tree[n + i] << "endl;"
        }
        build();
    }

    void build()
    {
        for (int i = n - 1 ; i > 0 ; --i) tree[i] = max(tree[i<<1],tree[i<<1|1]);
    }

    int query(int l,int r)
    {
        int res = -INFF;
        for (l += n, r += n; l < r; l >>= 1ll, r >>= 1ll) {
            if (l&1ll) res = max(res,tree[l++]);
            if (r&1ll) res = max(res,tree[--r]);
        }
        return res;
    }

    int qry(int l,int r)
    {
        return query(l,r + 1);
    }
};


void solve()
{
    int n;
    cin >> n;
    vector<int> tab(n + 5);
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> tab[i];
    }
    int x;
    cin >> x;
    vector<int> sum(n + 5,0);
    int cur = 0;
    sum[0] = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        cur += tab[i];
        sum[i] = cur - x * i;
        // cerr << sum[i] << " ";
    }
    // cerr << endl;
    segtree T(n + 1,sum);
    // cerr << T.qry(1,3) << endl;
    int lastUsed = -INFF;
    int ans = n;
    for (int i = 2 ; i <= n ; i++)
    {
        int tmp = sum[i];
        const auto good = [&](int a) -> bool
        {
            if (a == -1) return true;
            int mn = T.qry(a,i - 2);
            return (mn > tmp);
        };
        int l = -1;
        int r = i - 2;
        while (r - l > 1)
        {
            int mid = (l + r) >> 1ll;
            if (good(mid))
                l = mid;
            else
                r = mid - 1;
        }
        int take;
        if (good(r))
            take = r;
        else
        {
            assert(good(l));
            take = l;
        }
        // cerr << i << " " << take << " " << lastUsed << " " << l << " " << r << endl;
        if (lastUsed <= take && take != -1)
        {
            // cerr << "yo\n";
            --ans;
            lastUsed = i;
        }
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