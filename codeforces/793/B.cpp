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

struct node
{
    int r,c,dir,cnt;

    node(){};

    node(int _r,int _c,int _dir,int _cnt)
    {
        r = _r;
        c = _c;
        dir = _dir;
        cnt = _cnt;
    }
};

bool vis[1010][1010][3];

void solve()
{
    int n,m;
    cin >> n >> m;
    vector< vector<char> > tab(n,vector<char>(m));
    pair<int,int> awal,akhir;
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < m ; j++)
        {
            cin >> tab[i][j];
            if (tab[i][j] == 'S')
                awal = {i,j};
            if (tab[i][j] == 'T')
                akhir = {i,j};
        }

    const auto valid = [&](int i,int j,int k) -> bool
    {
        return (0 <= i && i < n && 0 <= j && j < m && tab[i][j] != '*' && !vis[i][j][k]);
    };

    vector<int> dx = {-1,0,1,0};
    vector<int> dy = {0,-1,0,1};

    queue< node > q;
    for (int i = 0 ; i < 4 ; i++)
    {
        int xx = awal.first + dx[i];
        int yy = awal.second + dy[i];
        if (valid(xx,yy,0))
        {
            vis[xx][yy][0] = 1;
            q.push(node(xx,yy,i,0));
        }
    }
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int x = cur.r;
        int y = cur.c;
        if (make_pair(x,y) == akhir)
        {
            cout << "YES\n";
            return;
        }
        int dir = cur.dir;
        int cnt = cur.cnt;
        for (int i = 0 ; i < 4 ; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            int tmpCnt = cnt + (i != dir);
            if (tmpCnt <= 2 && valid(xx,yy,tmpCnt))
            {
                q.push(node(xx,yy,i,tmpCnt));
                vis[xx][yy][tmpCnt] = 1;
            }
        }
    }
    cout << "NO\n";
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