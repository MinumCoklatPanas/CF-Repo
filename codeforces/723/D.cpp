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
#define MULTI_TC 0

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

int n,m,k;
char tab[55][55];
bool vis[55][55];
bool connect;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int cnt;

void dfs(int x,int y)
{
    if (x < 1 || x > n) return;
    if (y < 1 || y > m) return;
    if (vis[x][y]) return;
    if (tab[x][y] == '*') return;
    vis[x][y] = 1;
    if (x == 1 || x == n || y == 1 || y == m) connect = 1;
    ++cnt;
    for (int i = 0 ; i < 4 ; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        dfs(xx,yy);
    }
}

void color(int x,int y)
{
    if (x < 1 || x > n) return;
    if (y < 1 || y > m) return;
    if (vis[x][y]) return;
    if (tab[x][y] == '*') return;
    tab[x][y] = '*';
    for (int i = 0 ; i < 4 ; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        color(xx,yy);
    }
}

void solve()
{
    cin >> n >> m >> k;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= m ; j++)
        {
            cin >> tab[i][j];
        }
    }
    vector< pair<int,pair<int,int>> > lakes;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= m ; j++) if (!vis[i][j] && tab[i][j] == '.')
        {
            connect = 0;
            cnt = 0;
            dfs(i,j);
            if (!connect)
                lakes.push_back({cnt,{i,j}});
        }
    }
    sort(lakes.begin(),lakes.end());
    int need = lakes.size() - k;
    memset(vis,0,sizeof(vis));
    int ans = 0;
    for (int i = 0 ; i < need ; i++)
    {
        ans += lakes[i].first;
        color(lakes[i].second.first,lakes[i].second.second);
    }
    cout << ans << endl;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= m ; j++)
            cout << tab[i][j];
        cout << endl;
    }
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