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
#define int long long

int paritas[200010];
int cnt[2][200010];
int tab[200010];
vector<int> adj[200010];

int dfs(int u, int prv, int bit)
{
    paritas[u] = paritas[prv];
    paritas[u] ^= ((tab[u] & (1 << bit)) > 0);
    // cout << u << " " << ((tab[u] & (1 << bit)) > 0) << " " << paritas[u] << endl;
    int ret = 0;
    int tot0 = 0;
    int tot1 = 0;
    vector<int> val0;
    vector<int> val1;
    for (auto it : adj[u]) if (it != prv)
    {
        ret += dfs(it, u, bit);
        int anak0 = cnt[0][it] + !(paritas[it]);
        // tot0 += anak0;
        val0.push_back(anak0);
        cnt[0][u] += anak0;
        if (paritas[prv])
            ret += (anak0) * (1 << bit);
        int anak1 = cnt[1][it] + (paritas[it]);
        val1.push_back(anak1);
        // tot1 += anak1;
        cnt[1][u] += anak1;
        if (!paritas[prv])
            ret += (anak1) * (1 << bit);
        // if (u == 3)
        //     cout << anak0 << " " << anak1 << endl;
    }
    if (paritas[prv])
        swap(val1,val0);
    for (auto it : val0) tot0 += it;
    for (auto it : val1) tot1 += it;
    // if (u == 3)
    if (((tab[u] & (1 << bit)) == 0))
    {
        for (int i = 0 ; i < val0.size() ; i++)
        {
            tot0 -= val0[i];
            tot1 -= val1[i];
            ret += tot0 * val1[i] * (1 << bit);
            ret += tot1 * val0[i] * (1 << bit);
        }
    }
    else
    {
        for (int i = 0 ; i < val0.size() ; i++)
        {
            tot0 -= val0[i];
            tot1 -= val1[i];
            ret += tot0 * val0[i] * (1 << bit);
            ret += tot1 * val1[i] * (1 << bit);
        }
    }
    // cout << u << " " << ret << " " << paritas[u] << endl;
    // cout << u << " " << ret << endl;
    return ret;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1 ; i <= n ; i++) cin >> tab[i], ans += tab[i];
    for (int i = 1 ; i < n ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0 ; i <= 20 ; i++)
    {
        memset(paritas,0,sizeof(paritas));
        memset(cnt,0,sizeof(cnt));
        ans += dfs(1, 0, i);
        cout << endl;
    }
    cout << ans << endl;
    return 0;
}