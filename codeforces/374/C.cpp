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
int dp[1010][1010];
int in[1010][1010];
int n,m;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

bool valid(int x,int y)
{
    return ((1 <= x) && (x <= n) && (1 <= y) && (y <= m)); 
}

bool cyclic()
{
    queue< pair<int,int> > q;
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= m ; j++) if (in[i][j] == 0)
        {
            // cout << i << " " << j << endl;
            q.push({i,j});
        }
    // cout << in[2][2] << endl;
    while (!q.empty())
    {
        auto cur = q.front();
        // cout << cur.first << " " << cur.second << ": ";
        q.pop();
        for (int i = 0 ; i < 4 ; i++)
        {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            if (valid(x,y))
            {   
                // cout << x << " a " << y << endl;
                if (tab[cur.first][cur.second] == 'D' && tab[x][y] == 'I')
                {
                    --in[x][y];
                    // cout << x << "," << y << "," << in[x][y] << " ";
                    if (in[x][y] == 0)
                        q.push({x,y});
                }
                if (tab[cur.first][cur.second] == 'I' && tab[x][y] == 'M')
                {
                    --in[x][y];
                    // cout << x << "," << y << "," << in[x][y] << " ";
                    if (in[x][y] == 0)
                        q.push({x,y});
                }
                if (tab[cur.first][cur.second] == 'M' && tab[x][y] == 'A')
                {
                    --in[x][y];
                    // cout << x << "," << y << "," << in[x][y] << " ";
                    if (in[x][y] == 0)
                        q.push({x,y});
                }
                if (tab[cur.first][cur.second] == 'A' && tab[x][y] == 'D')
                {
                    --in[x][y];
                    // cout << x << "," << y << "," << in[x][y] << " ";
                    if (in[x][y] == 0)
                        q.push({x,y});
                }
            }
        }
        // cout << endl;
    }
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= m ; j++)
        {
            if (in[i][j] != 0)
            {
                // cout << i << " " << j << " " << in[i][j] << endl;
                return true;
            }
        }
    return false;
}

int rec(int x,int y)
{
    if (dp[x][y] != -1) return dp[x][y];
    int ret = 0;
    for (int i = 0 ; i < 4 ; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (valid(xx,yy))
        {
            if (tab[x][y] == 'D' && tab[xx][yy] == 'I')
            {
                ret = max(ret,rec(xx,yy));
            }
                
            if (tab[x][y] == 'I' && tab[xx][yy] == 'M')
            {
                ret = max(ret,rec(xx,yy));
            }
                
            if (tab[x][y] == 'M' && tab[xx][yy] == 'A')
            {
                ret = max(ret,rec(xx,yy));
            }
                
            if (tab[x][y] == 'A' && tab[xx][yy] == 'D')
            {
                ret = max(ret,rec(xx,yy));
            }
                
        }
    }
    // cout << x << " " << y << " " << ret << endl;
    return dp[x][y] = ret + (tab[x][y] == 'A');
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= m ; j++)
            cin >> tab[i][j];
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= m ; j++)
        {
            for (int k = 0 ; k < 4 ; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if (valid(x,y))
                {
                    if (tab[i][j] == 'D' && tab[x][y] == 'I')
                        ++in[x][y];
                    if (tab[i][j] == 'I' && tab[x][y] == 'M')
                        ++in[x][y];
                    if (tab[i][j] == 'M' && tab[x][y] == 'A')
                        ++in[x][y];
                    if (tab[i][j] == 'A' && tab[x][y] == 'D')
                        ++in[x][y];
                }
            }
        }
    vector< pair<int,int> > start;
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= m ; j++)
        {
            if (tab[i][j] == 'D')
            {
                // cout << i << " " << j << endl;
                start.emplace_back(i,j);
            }
        }
    if (start.size() == 0)
    {
        cout << "Poor Dima!\n";
        return 0;
    }
    if (cyclic())
    {
        cout << "Poor Inna!\n";
        return 0;
    }
    int ans = 0;
    memset(dp,-1,sizeof(dp));
    for (auto it : start)
    {
        int ret = rec(it.first,it.second);
        // cout << it.first << " " << it.second << ": " << ret << endl;
        ans = max(ans,ret);
        // return 0;
    }
    if (ans == 0)   
        cout << "Poor Dima!\n";
    else
        cout << ans << endl;
    return 0;
}