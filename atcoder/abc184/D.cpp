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

double dp[110][110][110];
bool vis[110][110][110];

double rec(int a,int b,int c)
{
    if (a == 100 || b == 100 || c == 100) return 0.0;
    if (vis[a][b][c]) return dp[a][b][c];
    vis[a][b][c] = 1;
    double tot = a + b + c;
    double ret = 0.0;
    if (a > 0) 
        ret += (1.0 * a / tot) * (1 + rec(a + 1,b,c));
    if (b > 0)
        ret += (1.0 * b / tot) * (1 + rec(a,b + 1,c));
    if (c > 0)
        ret += (1.0 * c / tot) * (1 + rec(a,b,c + 1));
    return dp[a][b][c] = ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,b,c;
    cin >> a >> b >> c;
    double ans = rec(a,b,c);
    cout << setprecision(9) << fixed;
    cout << ans << endl;
    return 0;
}