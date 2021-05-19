#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
// #define int long long
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool dp[501][501][501];
bool vis[501][501][501];
int tab[510];
int n,k;

bool rec(int ix,int sisaA,int sisaB)
{
    // cout << ix << " " << sisaA << " " << sisaB << endl;
    if (ix > n) return (sisaA == 0 && sisaB == 0);
    if (vis[ix][sisaA][sisaB]) return dp[ix][sisaA][sisaB];
    bool ret = rec(ix + 1,sisaA,sisaB);
    if (tab[ix] <= sisaA && tab[ix] <= sisaB)
    {
        ret |= rec(ix + 1,sisaA - tab[ix],sisaB - tab[ix]);
    }
    if (tab[ix] <= sisaB)
    {
        ret |= rec(ix + 1,sisaA,sisaB - tab[ix]);
    }
    vis[ix][sisaA][sisaB] = 1;
    return dp[ix][sisaA][sisaB] = ret;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++) cin >> tab[i];
    vector<int> ans;
    for (int i = 0 ; i <= k ; i++)
    {
        bool can = rec(1,i,k);
        if (can)
            ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}