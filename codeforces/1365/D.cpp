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

char tab[55][55];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
bool vis[55][55];
int n,m;

void dfs(int x,int y)
{
    if (x < 1) return;
    if (x > n) return;
    if (y < 1) return;
    if (y > m) return;
    if (tab[x][y] == '#') return;
    if (vis[x][y]) return;
    vis[x][y] = 1;
    for (int i = 0 ; i < 4 ; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        dfs(xx,yy);
    }
    return;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= m ; j++)
        {
            cin >> tab[i][j];
        }
    }
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= m ; j++) if (tab[i][j] == 'B')
        {
            for (int k = 0 ; k < 4 ; k++)
            {
                int ii = i + dx[k];
                int jj = j + dy[k];
                if (tab[ii][jj] == '.') tab[ii][jj] = '#';
            }
        }
    }
    memset(vis,0,sizeof(vis));
    dfs(n,m);
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= m ; j++)
        {
            if  (tab[i][j] == 'G')
            {
                if (!vis[i][j])
                {
                    cout << "No\n";
                    return;
                }
            }
            if (tab[i][j] == 'B')
            {
                if (vis[i][j])
                {
                    cout << "No\n";
                    return;
                }
            }
        }
    }
    cout << "Yes\n";
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