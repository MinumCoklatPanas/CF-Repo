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

int nxt[200010];
int cost[200010];
int deg[200010];
bool vis[200010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(nxt,-1,sizeof(nxt));
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> cost[i];
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        if (i != ta)
        {
            deg[ta]++;
            nxt[i] = ta;
        }
    }
    queue<int> q;
    for (int i = 1 ; i <= n ; i++) if (deg[i] == 0)
        q.push(i);
    int ans = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (nxt[cur] == -1)
        {
            ans += cost[cur];
        }
        else
        {
            --deg[nxt[cur]];
            if (deg[nxt[cur]] == 0)
                q.push(nxt[cur]);
        }
    }
    for (int i = 1 ; i <= n ; i++) if (deg[i] != 0 && !vis[i])
    {
        int mn = INF;
        int cur = i;
        do 
        {
            mn = min(mn,cost[cur]);
            vis[cur] = 1;
            cur = nxt[cur];
        } while (cur != i);
        ans += mn;
    }
    cout << ans << endl;
    return 0;
}