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

int tree[800010];
int pref[200010];
int tab[200010];

void build(int node,int l,int r)
{
    if (l == r)
    {
        tree[node] = pref[l];
        return;
    }
    int mid = (l + r) >> 1;
    int child = node << 1;
    build(child,l,mid);
    build(child | 1,mid + 1,r);
    tree[node] = min(tree[child],tree[child | 1]);
}

int query(int node,int nodeL,int nodeR,int queryL,int queryR)
{
    if (queryL > nodeR || queryR < nodeL) return INFF;
    if (queryL <= nodeL && nodeR <= queryR) return tree[node];
    int child = node << 1;
    int mid = (nodeL + nodeR) >> 1;
    return min(query(child,nodeL,mid,queryL,queryR),query(child | 1,mid + 1,nodeR,queryL,queryR)); 
}

void solve()
{
    int n,s;
    cin >> n >> s;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> tab[i];
        pref[i] = pref[i - 1] + tab[i];
    }
    build(1,1,n);
    int len = 0;
    int ansL = -1,ansR = -1;
    for (int i = 1 ; i <= n ; i++)
    {
        int sum = pref[i - 1] - s;
        // cerr << i << " " << sum << endl;
        int l = i;
        int r = n;
        while (r - l > 1)
        {
            int mid = (l + r) >> 1;
            int cur = query(1,1,n,i,mid);
            if (cur < sum)
                r = mid - 1;
            else
                l = mid;
        }
        int tmp = query(1,1,n,i,r);
        int ki = i;
        int ka = -1;
        if (tmp >= sum)
            ka = r;
        else
        {
            tmp = query(1,1,n,i,l);
            if (tmp >= sum)
                ka = l;
        }
        // cerr << ki << " " << ka << endl;
        int tmpLen = ka - ki + 1;
        if (tmpLen > len)
        {
            len = tmpLen;
            ansL = ki;
            ansR = ka;
        }
    }   
    if (len == 0)
        cout << -1 << endl;
    else
        cout << ansL << " " << ansR << endl;
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