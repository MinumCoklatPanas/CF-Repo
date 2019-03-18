#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MOD = 1e9 + 7;
const ll MAXN = 210;

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


inline void writeInt (ll n)
{
    ll NN = n, rev, count = 0;
    rev = NN;
    if (NN == 0) { putchar('0');  return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (NN != 0) { rev = (rev<<3) + (rev<<1) + NN % 10; NN /= 10;}  //store reverse of N in rev
    while (rev != 0) { putchar(rev % 10 + '0'); rev /= 10;}
    while (count--) putchar('0');
}

ll tree[MAXN][4 * MAXN];
ll tab[MAXN];

void build(ll node,ll l,ll r,ll kode)
{
    if (l == r)
    {
        tree[kode][node] = -INFF;
        return;
    }
    ll child = node << 1;
    ll mid = (l + r) >> 1;
    build(child,l,mid,kode);
    build(child | 1,mid + 1,r,kode);
    tree[kode][node] = -INFF;
}

void upd(ll node,ll l,ll r,ll ix,ll val,ll kode)
{
    if (l == r)
    {
        tree[kode][node] = val;
        return;
    }
    ll child = node << 1;
    ll mid = (l + r) >> 1;
    if (ix > mid)
        upd(child | 1,mid + 1,r,ix,val,kode);
    else
        upd(child,l,mid,ix,val,kode);
    tree[kode][node] = max(tree[kode][child],tree[kode][child | 1]);
}

ll query(ll node,ll nodeL,ll nodeR,ll queryL,ll queryR,ll kode)
{
    if (queryL > nodeR || queryR < nodeL) return -INFF;
    // cout << node << " " << nodeL << " " << nodeR << " " << queryL << " " << queryR << " " << kode << endl;
    if (queryL <= nodeL && nodeR <= queryR)
    {
        // cout << tree[kode][node] << endl;
        return tree[kode][node];
    }
    ll child = node << 1;
    ll mid = (nodeL + nodeR) >> 1;
    return max(query(child,nodeL,mid,queryL,queryR,kode),query(child | 1,mid + 1,nodeR,queryL,queryR,kode));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    ll n,k,x;
    cin >> n >> k >> x;
    for (ll i = 1 ; i <= n ; i++)
        cin >> tab[i];
    for (ll i = 0 ; i <= x ; i++)
        build(1,0,n,i);
    upd(1,0,n,0,0,x);
    for (ll i = 1 ; i <= n ; i++)
    {
        // cout << "=============================\n";
        for (ll j = 0 ; j < x ; j++)
        {
            // if (i == n && j == x - 1)
            // {
            //     cout << "INI\n";
            // }
            ll mx = query(1,0,n,max(0ll,i - k),i - 1,j + 1);
            // if (i == n && j == x - 1)
            // {
            //     cout << mx << endl;
            //     cout << i - k << " " << i - 1 << endl;
            // }
            ll val = (mx == -INFF ? -INFF : mx + tab[i]);
            //DP[i][j] = val
            upd(1,0,n,i,val,j);
        }
        // cout << "=============================\n";
    }
    // for (int i = 1 ; i <= n ; i++)
    // {
    //     for (int j = 0 ; j <= x ; j++)
    //         cout << query(1,0,n,i,i,j) << " ";
    //     cout << endl;
    // }

    ll ans = -INFF;
    for (ll i = n - k + 1 ; i <= n ; i++)
    {
        for (ll j = 0 ; j <= x ; j++)
            //DP[i][j]
            ans = max(ans,query(1,0,n,i,i,j));
    }
    if (ans == -INFF)
        cout << -1 << endl;
    else
        cout << ans << endl;
}