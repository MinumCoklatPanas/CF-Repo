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

ll tree[800010];
ll laz[800010];

void upd(ll node,ll l,ll r,ll val)
{
    ll len = (r - l + 1);
    tree[node] += val * len;
    laz[node] += val;
    return;
}

void propagate(ll node,ll l,ll r)
{
    ll child = node << 1;
    ll mid = (l + r) >> 1;
    upd(child,l,mid,laz[node]);
    upd(child | 1,mid + 1,r,laz[node]);
    laz[node] = 0;
}

void pointUpdate(ll node,ll l,ll r,ll ix,ll val)
{
    if (l == r)
    {
        tree[node] = val;
        return;
    }
    propagate(node,l,r);
    ll mid = (l + r) >> 1;
    ll child = node << 1;
    if (ix > mid)
        pointUpdate(child | 1,mid + 1,r,ix,val);
    else
        pointUpdate(child,l,mid,ix,val);
    tree[node] = tree[child] + tree[child | 1];
}

void rangeUpdate(ll node,ll nodeL,ll nodeR,ll queryL,ll queryR,ll val)
{
    if (queryL > nodeR || queryR < nodeL) return;
    if (queryL <= nodeL && nodeR <= queryR)
    {
        upd(node,nodeL,nodeR,val);
        return;
    }
    propagate(node,nodeL,nodeR);
    ll child = node << 1;
    ll mid = (nodeL + nodeR) >> 1;
    rangeUpdate(child,nodeL,mid,queryL,queryR,val);
    rangeUpdate(child | 1,mid + 1,nodeR,queryL,queryR,val);
    tree[node] = tree[child] + tree[child | 1];
}

int main()
{
    // cout << "a\n";
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll q;
    cin >> q;
    ll siz = 1;
    while (q--)
    {
        ll ask;
        cin >> ask;
        if (ask == 1)
        {
            ll ix,x;
            cin >> ix >> x;
            rangeUpdate(1,1,200005,1,ix,x);
        }
        else
        if (ask == 2)
        {
            ll x;
            cin >> x;
            ++siz;
            pointUpdate(1,1,200005,siz,x);
        }
        else
        {
            if (siz == 1) continue;
            pointUpdate(1,1,200005,siz,0);
            --siz;
        }
        ll sum = tree[1];
        // cout << sum << ": sum\n";
        double ans = (double)sum / (double)siz;
        cout << setprecision(10) << fixed;
        cout << ans << endl;
    }
    return 0;
}