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

int tree[800010];
int tab[200010];
int n;

void build(int node,int l,int r)
{
    for (int i = 0 ; i < n ; i++) tree[n + i] = tab[i + 1];
    for (int i = n - 1 ; i > 0 ; i--) tree[i] = min(tree[i << 1],tree[i << 1 | 1]); 
}

int query(int node,int nodeL,int nodeR,int queryL,int queryR)
{
    int l = queryL - 1;
    int r = queryR;
    int ret = INF;
    for (l += n,r += n ; l < r ; l >>= 1,r >>= 1)
    {
        if (l & 1) ret = min(ret,tree[l++]);
        if (r & 1) ret = min(ret,tree[--r]);
    }
    return ret;
}

int maxLen[200010];

int cariKiri(int ix)
{
    int l = 1;
    int r = ix; 
    while (r - l > 1)
    {
        int mid = (l + r) >> 1;
        int mn = query(1,1,n,mid,ix);
        if (mn == tab[ix])
            r = mid;
        else
            l = mid + 1;
    }
    if (query(1,1,n,l,ix) == tab[ix])
        return l;
    else
        return r;
}

int cariKanan(int ix)
{
    int l = ix;
    int r = n;
    while (r - l > 1)
    {
        int mid = (l + r) >> 1;
        int mn = query(1,1,n,ix,mid);
        if (mn == tab[ix])
            l = mid;
        else
            r = mid - 1;
    } 
    if (query(1,1,n,ix,r) == tab[ix])
        return r;
    else
        return l;
}

int ans[200010];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> tab[i];
    build(1,1,n);
    for (int i = 1 ; i <= n ; i++)
    {
        int leftMost = cariKiri(i);
        int rightMost = cariKanan(i);
        int len = rightMost - leftMost + 1;
        // cout << tab[i] << " " << len << endl;
        maxLen[i] = len;
    }
    // cout << endl;
    memset(ans,-1,sizeof(ans));
    for (int i = 1 ; i <= n ; i++)
    {
        ans[maxLen[i]] = max(ans[maxLen[i]],tab[i]);
    }
    // for (auto it : maxLen)
    // {
    //     // cout << it.first << " " << it.second << endl;
    //     ans[it.second] = max(ans[it.second],it.first);
    // }
    // for (int i = 1 ; i <= n ; i++)
    //     cout << ans[i] << " ";
    // cout << endl;
    // for (int i = 1 ; i <= n ; i++) if (ans[i] == -1)
    //     ans[i] = ans[i - 1];
    for (int i = n ; i >= 1 ; i--)
        ans[i] = max(ans[i],ans[i + 1]);
    for (int i = 1 ; i <= n ; i++)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}