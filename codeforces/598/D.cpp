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

char tab[1010][1010];
int cnt[1010][1010];
pair<int,int> par[1010][1010];
bool vis[1010][1010];
int n,m,q;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

void dfs(int curR,int curC,int parR,int parC)
{
    if (curR < 1) return;
    if (curR > n) return;
    if (curC < 1) return;
    if (curC > m) return;
    if (tab[curR][curC] == '*') return;
    if (vis[curR][curC]) return;
    vis[curR][curC] = 1;
    par[curR][curC] = {parR,parC};
    // cout << curR << " " << curC << endl;
    for (int i = 0 ; i < 4 ; i++)
    {
        int RR = curR + dx[i];
        int CC = curC + dy[i];
        // cout << RR << " " << CC << " " << curR << " " << curC << endl;
        if (vis[RR][CC]) continue;
        dfs(RR,CC,parR,parC);
        cnt[curR][curC] += cnt[RR][CC];
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= m ; j++)
            cin >> tab[i][j];
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= m ; j++) if (tab[i][j] == '*')
        {
            for (int k = 0 ; k < 4 ; k++)
            {
                int ii = i + dx[k];
                int jj = j + dy[k];
                if (1 <= ii && ii <= n && 1 <= jj && jj <= m && tab[ii][jj] == '.')
                    ++cnt[ii][jj];
            }
        }
    // for (int i = 1 ; i <= n ; i++)
    // {
    //     for (int j = 1 ; j <= m ; j++)
    //         cout << cnt[i][j] << " ";
    //     cout << endl;
    // }
    // cout << endl;
    // dfs(4,3,4,3);
    // return 0;
    memset(par,-1,sizeof(par));
    while (q--)
    {
        int x,y;
        cin >> x >> y;
        if (par[x][y].first == -1)
            dfs(x,y,x,y);
        // for (int i = 1 ; i <= n ; i++)
        // {
        //     for (int j = 1 ; j <= m ; j++)
        //         cout << cnt[i][j] << " ";
        //     cout << endl;
        // }
        cout << cnt[par[x][y].first][par[x][y].second] << endl;
    }
    return 0;
}