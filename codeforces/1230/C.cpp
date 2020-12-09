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

int tab[10];
pair<int,int> edge[30];
int n,m;
bool ada[10][10];

int rec(int depth)
{
    if (depth > n)
    {
        memset(ada,0,sizeof(ada));
        for (int i = 1 ; i <= m ; i++)
        {
            int u = edge[i].first;
            int v = edge[i].second;
            if (u != 0 && v != 0)
            {
                ada[tab[u]][tab[v]] = ada[tab[v]][tab[u]] = 1;
            }
        }
        // for (int i = 1 ; i <= n ; i++)
        //     cout << tab[i] << " ";
        // cout << endl;
        int cnt = 0;
        for (int i = 1 ; i <= n ; i++)
            for (int j = i ; j <= n ; j++)
                cnt += ada[i][j];
        return cnt;
    }
    int ret = 0;
    for (int i = 0 ; i <= 6 ; i++)
    {
        tab[depth] = i;
        ret = max(ret,rec(depth + 1));
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++)
        cin >> edge[i].first >> edge[i].second;
    int ans = rec(1);
    cout << ans << endl;
    return 0;
}