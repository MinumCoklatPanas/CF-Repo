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

bool vis[1010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;   
    int cur = 1;
    vis[1] = 1;
    for (int i = 1 ; i <= n ; i++)
    {
        cur += i;
        cur %= n;
        if (cur == 0)
            cur = n;
        vis[cur] = 1;
    }
    for (int i = 1 ; i <= n ; i++) if (!vis[i])
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    return 0;
}