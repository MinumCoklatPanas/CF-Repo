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

bool ada[1010];
int nxt[1010];
int adj[1010][1010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    memset(nxt,-1,sizeof(nxt));
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a][b] = c;
        ada[b] = 1;
        nxt[a] = b;
    }
    vector< pair<int,pair<int,int>> > ans;
    for (int i = 1 ; i <= n ; i++) if (!ada[i])
    {
        int mn = INF;
        int cur = i;
        while (nxt[cur] != -1)
        {
            mn = min(mn,adj[cur][nxt[cur]]);
            cur = nxt[cur];
        }
        if (i != cur)
            ans.push_back({i,{cur,mn}});
    }
    cout << ans.size() << endl;
    for (auto it : ans)
        cout << it.first << " " << it.second.first << " " << it.second.second << endl;
    return 0;
}