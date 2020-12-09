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

int par[150010];
int leftMost[150010];
int rightMost[150010];

int finds(int x)
{
    return (par[x] == x ? x : par[x] = finds(par[x]));
}

vector<int> adj[150010];
int deg[150010];

void joins(int x,int y)
{
    int px = finds(x);
    int py = finds(y);
    if (px == py) { assert(false); return;}
    par[px] = py;
    //ujung kanan px sambung ke ujung kiri py
    // cout << rightMost[px] << " " << leftMost[py] << endl;
    adj[rightMost[px]].push_back(leftMost[py]);
    ++deg[leftMost[py]];
    //ujung kiri py jadi ujung kiri px
    leftMost[py] = leftMost[px];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++) par[i] = leftMost[i] = rightMost[i] = i;
    for (int i = 1 ; i < n ; i++)
    {
        int u,v;
        cin >> u >> v;
        // cout << "-----------------------\n";
        joins(u,v);
        // for (int j = 1 ; j <= n ; j++)
        // {
        //     int p = finds(j);
        //     // cout << j << " " << p << " " << leftMost[p] << " " << rightMost[p] << endl;
        // }
        // cout << "-----------------------\n";
    }
    // queue<int> q;
    // for (int i = 1 ; i <= n ; i++) if (deg[i] == 0)
    //     q.push(i);
    int cnt = 0;
    int start = leftMost[finds(1)];
    while (adj[start].size() != 0)
    {
        cout << start << " ";
        if (adj[start].size() != 1)
        {
            cout << "hehe\n";
            return 0;
        }
        // assert(adj[start].size() == 1);
        start = adj[start][0];
    }
    cout << start << endl;
    cout << endl;
    return 0;
}