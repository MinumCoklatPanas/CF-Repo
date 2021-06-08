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

int dp[5010][5010];
vector<int> isi,kosong;
int n;

int rec(int ixA,int ixB)
{
    if (ixA == isi.size()) return 0;
    if (ixB == kosong.size()) return INFF;
    if (dp[ixA][ixB] != -1) return dp[ixA][ixB];
    int ret = rec(ixA + 1,ixB + 1) + abs(isi[ixA] - kosong[ixB]);
    ret = min(ret,rec(ixA,ixB + 1));
    return dp[ixA][ixB] = ret;
}

void solve()
{
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        if (ta)
            isi.push_back(i);
        else
            kosong.push_back(i);
    }
    memset(dp,-1,sizeof(dp));
    int ans = rec(0,0);
    cout << ans << endl;
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