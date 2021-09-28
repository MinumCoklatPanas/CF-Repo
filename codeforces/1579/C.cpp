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

int n,m,k;
char tab[15][25];
bool vis[15][25];

bool valid(pair<int,int> x)
{
    return ((1 <= x.first && x.first <= n) && (1 <= x.second && x.second <= m) && (tab[x.first][x.second] == '*'));
}

int cnt(pair<int,int> pos)
{
    pair<int,int> kiri = pos;
    pair<int,int> kanan = pos;
    kiri.first--;
    kiri.second--;
    kanan.first--;
    kanan.second++;
    // cerr << valid(kanan) << endl;
    int res = 0;
    while (valid(kiri) && valid(kanan))
    {
        ++res;
        kiri.first--;
        kiri.second--;
        kanan.first--;
        kanan.second++;
    }
    return res;
}

void mark(pair<int,int> pos)
{
    vis[pos.first][pos.second] = 1;
    pair<int,int> kiri = pos;
    pair<int,int> kanan = pos;
    kiri.first--;
    kiri.second--;
    kanan.first--;
    kanan.second++;
    while (valid(kiri) && valid(kanan))
    {
        vis[kiri.first][kiri.second] = 1;
        vis[kanan.first][kanan.second] = 1;
        kiri.first--;
        kiri.second--;
        kanan.first--;
        kanan.second++;
    }
}

void solve()
{
    memset(vis,0,sizeof(vis));
    cin >> n >> m >> k;
    for (int i = 1 ; i <= n ; i++) 
        for (int j = 1 ; j <= m ; j++)
            cin >> tab[i][j];
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= m ; j++) if (tab[i][j] == '*')
        {
            int depth = cnt(make_pair(i,j));
            // cerr << i << " " << j << " " << depth << endl;
            if (depth >= k)
                mark(make_pair(i,j));
        }
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= m ; j++)
        {
            if (tab[i][j] == '*' && !vis[i][j])
            {
                // cerr << i << " " << j << ": problem\n"; 
                cout << "NO\n";
                return;
            }
        }
    cout << "YES\n";
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