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

map<int,queue<int>> mp;
int tab[100010];
int pref[100010];

int get(int l,int r)
{
    return pref[r] - pref[l - 1];
}

int tree[400010];

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
    tree[node] = max(tree[child],tree[child | 1]);
}

int query(int node,int nodeL,int nodeR,int queryL,int queryR)
{
    if (queryL > nodeR || queryR < nodeL) return -INF;
    if (queryL <= nodeL && nodeR <= queryR) return tree[node];
    int mid = (nodeL + nodeR) >> 1;
    int child = node << 1;
    return max(query(child,nodeL,mid,queryL,queryR),query(child | 1,mid + 1,nodeR,queryL,queryR));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> tab[i];
        mp[tab[i]].push(i);
        pref[i] = pref[i - 1] + tab[i];
    }
    build(1,1,n);
    int ans = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        mp[tab[i]].pop();
        int curMx = tab[i];
        while (1)
        {
            int nxtMx = n + 1;
            for (int j = curMx + 1 ; j <= 30 ; j++) if (!mp[j].empty())
                nxtMx = min(nxtMx,mp[j].front());
            int cur = nxtMx - 1;
            int maxSum = query(1,1,n,i,cur) - pref[i - 1] - curMx;
            ans = max(ans,maxSum);
            if (nxtMx == n + 1) break;
            curMx = tab[nxtMx];
        }
    }
    cout << ans << endl;
    return 0;
}