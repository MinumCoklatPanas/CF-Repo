#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

ll readInt ()
{
    bool minus = false;
    ll result = 0;
    char ch;
    ch = getchar();
    while (true)
    {
            if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true;
    else result = ch-'0';
    while (true)
    {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

struct seg
{
    ll nol;
    ll satu;
};


ll tab[100010];
seg tree[20][400010];
bool lazy[20][400010];

void build(ll node,ll l,ll r,ll bit)
{
    if (l == r)
    {
        tree[bit][node].nol = (tab[l] & (1 << bit)) == 0;
        tree[bit][node].satu = (tab[l] & (1 << bit)) != 0;
        return;
    }
    ll mid = (l + r) >> 1;
    ll child = node << 1;
    build(child,l,mid,bit);
    build(child | 1,mid + 1,r,bit);
    tree[bit][node].nol = tree[bit][child].nol + tree[bit][child | 1].nol;
    tree[bit][node].satu = tree[bit][child].satu + tree[bit][child | 1].satu;
}

void upd(ll node,ll bit)
{
    swap(tree[bit][node].nol,tree[bit][node].satu);
    lazy[bit][node] ^= 1;
}

void propagate(ll node,ll bit)
{
    if (!lazy[bit][node]) return;
    ll child = node << 1;
    upd(child,bit);
    upd(child | 1,bit);
    lazy[bit][node] = 0;
}

void rangeUpdate(ll node,ll nodeL,ll nodeR,ll queryL,ll queryR,ll bit)
{
    if (queryL > nodeR || queryR < nodeL) return;
    if (queryL <= nodeL && nodeR <= queryR)
    {
        upd(node,bit);
        return;
    }
    propagate(node,bit);
    ll child = node << 1;
    ll mid = (nodeL + nodeR) >> 1;
    rangeUpdate(child,nodeL,mid,queryL,queryR,bit);
    rangeUpdate(child | 1,mid + 1,nodeR,queryL,queryR,bit);
    tree[bit][node].nol = tree[bit][child].nol + tree[bit][child | 1].nol;
    tree[bit][node].satu = tree[bit][child].satu + tree[bit][child | 1].satu;
}

ll rangeQuery(ll node,ll nodeL,ll nodeR,ll queryL,ll queryR,ll bit)
{
    if (queryL > nodeR || queryR < nodeL) return 0;
    if (queryL <= nodeL && nodeR <= queryR)
    {
        return tree[bit][node].satu;
    }
    propagate(node,bit);
    ll child = node << 1;
    ll mid = (nodeL + nodeR) >> 1;
    return rangeQuery(child,nodeL,mid,queryL,queryR,bit) + rangeQuery(child | 1,mid + 1,nodeR,queryL,queryR,bit);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    for (ll i = 1 ; i <= n ; i++)
        cin >> tab[i];
    for (ll i = 0 ; i < 20 ; i++)
        build(1,1,n,i);
    ll q;
    cin >> q;
    while (q--)
    {
        ll ask;
        cin >> ask;
        if (ask == 1)
        {
            ll l,r;
            cin >> l >> r;
            ll ans = 0;
            for (ll i = 0 ; i < 20 ; i++)
            {
                ll tmp = rangeQuery(1,1,n,l,r,i);
                ans += tmp * (1 << i);
            }
            cout << ans << endl;
        }
        else
        {
            ll l,r,x;
            cin >> l >> r >> x;
            for (ll i = 0 ; i < 20 ; i++) if (x & (1 << i))
            {
                rangeUpdate(1,1,n,l,r,i);
            }
        }
    }
    return 0;
}