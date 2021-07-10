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

int dp[110][110];
int a[110];
int b[110];
int prefA[110];
int prefB[110];
int n,m,k;
vector<int> ans;

int rec(int x,int y)
{
    if (x == n + 1 && y == m + 1) return 1;
    if (dp[x][y] != -1) return dp[x][y];
    int curPage = k + prefA[x - 1] + prefB[y - 1];
    int ret = 0;
    bool done = 0;
    if (x <= n)
    {
        if (a[x] == 0)
        {
            ret |= rec(x + 1,y);
        }
        else
        if (curPage >= a[x])
        {
            ret |= rec(x + 1,y);
        }
    }


    // cerr << x << ' ' << y << " " << done << " done\n";
    if (y <= m)
    {
        if (b[y] == 0)
        {
            ret |= rec(x,y + 1);
        }
        else
        if (curPage >= b[y])
        {
            ret |= rec(x,y + 1);
        }
    }
    return dp[x][y] = ret;
}

void backtrack(int x,int y)
{
    if (x == n + 1 && y == m + 1) return;
    bool done = 0;
    if (x <= n)
    {
        if (rec(x + 1,y))
        {
            ans.push_back(a[x]);
            backtrack(x + 1,y);
            done = 1;
        }
    }
    if (y <= m && !done)
    {
        if (rec(x,y + 1))
        {
            ans.push_back(b[y]);
            backtrack(x,y + 1);
            done = 1;
        }
    }
}

void solve()
{
    memset(dp,-1,sizeof(dp));
    memset(prefA,0,sizeof(prefA));
    memset(prefB,0,sizeof(prefB));
    ans.clear();
    cin >> k >> n >> m;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        prefA[i] = prefA[i - 1] + (a[i] == 0);
    }
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> b[i];
        prefB[i] = prefB[i - 1] + (b[i] == 0);
    }
    int curPage = k;
    int ptrA = 1;
    int ptrB = 1;
    for (int i = 1 ; i <= n + m ; i++)
    {
        if (ptrA <= n && a[ptrA] == 0)
        {
            ans.push_back(0);
            ++curPage;
            ++ptrA;
        }
        else
        if (ptrB <= m && b[ptrB] == 0)
        {
            ans.push_back(0);
            ++curPage;
            ++ptrB;
        }
        else
        if (ptrA <= n && a[ptrA] <= curPage)
        {
            ans.push_back(a[ptrA]);
            ++ptrA;
        }
        else
        if (ptrB <= m && b[ptrB] <= curPage)
        {
            ans.push_back(b[ptrB]);
            ++ptrB;
        }
        else
        {
            cout << -1 << endl;
            return;
        }
    }
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
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