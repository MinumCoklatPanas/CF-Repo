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

int par[100010];
int numset;

int finds(int x)
{
    return (par[x] == x ? x : par[x] = finds(par[x]));
}

void joins(int x,int y)
{
    int px = finds(x);
    int py = finds(y);
    if (px == py) return;
    par[px] = py;
    --numset;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) par[i] = i;
    numset = n;
    for (int i = 1 ; i <= m ; i++)
    {
        int a,b;
        cin >> a >> b;
        joins(a,b);
    }
    cout << numset - 1 << endl;
    return 0;
}