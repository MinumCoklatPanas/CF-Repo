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

ll tab[200010];
ll nxt[200010];
ll in[200010];
bool vis[200010];
ll ans;
vector<int> take;

void dfs(ll cur)
{
    if (cur == -1 || tab[cur] < 0) return;
    vis[cur] = 1;
    take.push_back(cur);
    if (nxt[cur] != -1)
        tab[nxt[cur]] += tab[cur];
    dfs(nxt[cur]);
    // ll tmp = dfs(nxt[cur]);
    // cout << tab[cur] << " " << tmp << endl;
    ans += tab[cur];
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    for (ll i = 1 ; i <= n ; i++)
    {
        cin >> tab[i];
    }
    for (ll i = 1 ; i <= n ; i++)
    {
        cin >> nxt[i];
        if (nxt[i] != -1)
            in[nxt[i]]++;
    }
    queue<ll> q;
    for (ll i = 1 ; i <= n ; i++) if (in[i] == 0)
        q.push(i);
    vector<ll> topo;
    while (!q.empty())
    {
        ll cur = q.front();
        q.pop();
        topo.push_back(cur);
        if (nxt[cur] != -1)
        {
            in[nxt[cur]]--;
            if (in[nxt[cur]] == 0)
                q.push(nxt[cur]);
        }
    }
    // for (auto it : topo)
    //     cout << it << " ";
    // cout << endl;
    for (ll i = 0 ; i < n ; i++) if (!vis[topo[i]] && tab[topo[i]] > 0)
    {
        vis[topo[i]] = 1;
        take.push_back(topo[i]);
        ans += tab[topo[i]];
        if (nxt[topo[i]] != -1)
        {
            tab[nxt[topo[i]]] += tab[topo[i]];
        }
    }
    for (ll i = n - 1 ; i >= 0 ; i--) if (!vis[topo[i]])
    {
        take.push_back(topo[i]);
        ans += tab[topo[i]];
    }
    assert(take.size() == n);
    cout << ans << endl;
    for (auto it : take)
        cout << it << " ";
    cout << endl;
    return 0;
}