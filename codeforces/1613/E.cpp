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
#define MULTI_TC 1

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

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<char>> tab(n,vector<char>(m));
    vector<vector<bool>> vis(n,vector<bool>(m,0));
    int posX,posY;
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < m ; j++)
        {
            cin >> tab[i][j];
            if (tab[i][j] == 'L')
            {
                posX = i;
                posY = j;
            }
        }
    queue<pair<int,int>> q;        
    q.push({posX,posY});
    int dx[] = {-1,0,1,0};
    int dy[] = {0,-1,0,1};
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;
        // cerr << x << " " << y << endl;
        int cnt = 0;
        for (int i = 0 ; i < 4 ; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            // cerr << xx << " " << yy << " xx\n";
            if (0 <= xx && xx < n && 0 <= yy && yy < m && (tab[xx][yy] == '.') && !vis[xx][yy])
            {
                int cnt = 0;
                for (int j = 0 ; j < 4 ; j++)
                {
                    int a = xx + dx[j];
                    int b = yy + dy[j];
                    if (0 <= a && a < n && 0 <= b && b < m && tab[a][b] == '.')
                        ++cnt;
                }
                if (cnt <= 1)
                {
                    tab[xx][yy] = '+';
                    q.emplace(xx,yy);
                    vis[xx][yy] = 1;
                }
            }
        }
    }
    // cerr << "yo\n";
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < m ; j++)
        {
            cout << tab[i][j];
        }
        cout << "\n";
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