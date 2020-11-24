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
    tree[node] = min(tree[child],tree[child | 1]);
    return;
}

int query(int node,int nodeL,int nodeR,int queryL,int queryR)
{
    if (queryL > nodeR || queryR < nodeL) return INF;
    if (queryL <= nodeL && nodeR <= queryR) return tree[node];
    int mid = (nodeL + nodeR) >> 1;
    int child = node << 1;
    return min(query(child,nodeL,mid,queryL,queryR),query(child | 1,mid + 1,nodeR,queryL,queryR));
}

int prefMax[200010];
int sufMax[200010];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> tab[i];
    build(1,1,n);
    prefMax[0] = sufMax[n + 1] = 0;
    for (int i = 1 ; i <= n ; i++) prefMax[i] = max(prefMax[i - 1],tab[i]);
    for (int i = n ; i >= 1 ; i--) sufMax[i] = max(sufMax[i + 1],tab[i]);
    for (int i = 1 ; i + 2 <= n ; i++)
    {
        int kiri = prefMax[i];
        if (tab[i + 1] < kiri) continue;
        if (query(1,1,n,i + 1,n - 1) > kiri) continue;
        // cout << i <<" " << masuk << endl;
        int batasKiri = -1, batasKanan = -1;
        int l = i + 1;
        int r = n - 1;
        while (r - l > 1)
        {
            int mid = (l + r) >> 1;
            int mn = query(1,1,n,i + 1,mid);
            if (mn > kiri)
                l = mid + 1;
            else
            if (mn < kiri)
                r = mid - 1;
            else
                r = mid;
        }
        if (query(1,1,n,i + 1,l) == kiri)
            batasKiri = l;
        else
        if (query(1,1,n,i + 1,r) == kiri)
            batasKiri = r;
        if (batasKiri == -1) continue;

        l = batasKiri;
        r = n - 1;
        while (r - l > 1)
        {
            int mid = (l + r) >> 1;
            int mn = query(1,1,n,i + 1,mid);
            if (mn > kiri)
                l = mid + 1;
            else
            if (mn < kiri)
                r = mid - 1;
            else
                l = mid;
        }
        if (query(1,1,n,i + 1,r) == kiri)
            batasKanan = r;
        else
        if (query(1,1,n,i + 1,l) == kiri)
            batasKanan = l;
        else
            assert(false);
        // cout << i << " " << batasKiri << " " << batasKanan << " " << kiri << " " << endl;
        int x = i;

        if (sufMax[batasKiri] < kiri) continue;
        l = batasKiri + 1;
        r = batasKanan + 1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (sufMax[mid] < kiri)
                r = mid - 1;
            else
            if (sufMax[mid] > kiri)
                l = mid + 1;
            else
            {
                int y = (mid - 1) - x;
                int z = n - (x + y);
                cout << "YES\n";
                cout << x << " " << y << " " << z << endl;
                return;
            }
        }
    }
    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}