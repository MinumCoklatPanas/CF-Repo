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

int tab[1010][1010];
int sum[1010];
int row[1010];
int col[1010];

void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            cin >> tab[i][j];
        }
        sum += tab[i][i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int ask;
        cin >> ask;
        if (ask == 3)
            cout << sum % 2;
        else
        {
            int x;
            cin >> x;
            sum -= tab[x][x];
            tab[x][x] ^= 1;
            sum += tab[x][x];
        }
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