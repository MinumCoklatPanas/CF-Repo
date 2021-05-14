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

int dp[1000010][2][2]; //[index][bef][masih bisa ganti 0]
int n,k;
string s;

int rec(int ix,int bef,int bisa)
{
    // cout << ix << " " << bef << " " << bisa << endl;
    if (ix >= n) return 0;
    if (dp[ix][bef][bisa] != -1) return dp[ix][bef][bisa];
    int ret = INF;
    //index sekarang 0
    if (bef == 1)
    {
        ret = min(ret,(s[ix] != '0') + rec(ix + k,0,0));
    }
    else
    {
        ret = min(ret,(s[ix] != '0') + rec(ix + k,0,bisa));
    }

    //index sekarang jadi 1
    if (bisa)
    {
        ret = min(ret,(s[ix] != '1') + rec(ix + k,1,bisa));
    }
    return dp[ix][bef][bisa] = ret;
}

void solve()
{
    cin >> n >> k;
    cin >> s;
    int tot1 = 0;
    for (int i = 0 ; i < n ; i++) tot1 += (s[i] == '1');
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < 2 ; j++)
        {
            for (int k = 0 ; k < 2 ; k++)
                dp[i][j][k] = -1;
        }
    }
    int ans = INF;
    for (int i = 0 ; i < min(n,k) ; i++)
    {
        int tmp = rec(i,0,1);
        int cur1 = 0;
        for (int j = i ; j < n ; j += k) cur1 += (s[j] == '1');
        int hapusLuar = tot1 - cur1;
        tmp += hapusLuar;
        ans = min(ans,tmp);
    }
    cout << ans << endl;
    // cout << "=================================\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}