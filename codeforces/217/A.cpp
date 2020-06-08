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

vector< pair<int,int> > tab;
bool vis[110];
int n;

void dfs(int ix)
{
    // cout << ix << endl;
    vis[ix] = 1;
    for (int i = 0 ; i < n ; i++) if (!vis[i])
    {
        int x = tab[i].first;
        int y = tab[i].second;
        // cout << i << " i\n";
        if (x == tab[ix].first || y == tab[ix].second)
            // cout << i << " i " << ix << endl;
            dfs(i);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        int x,y;
        cin >> x >> y;
        tab.emplace_back(x,y);
    }
    int ans = -1;
    for (int i = 0 ; i < n ; i++) if (!vis[i])
    {
        dfs(i);
        ++ans;
    }
    cout << ans << endl;
    return 0;
}