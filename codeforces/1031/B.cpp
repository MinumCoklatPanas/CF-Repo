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

int a[100010];
int b[100010];
int ans[100010];
int dp[100010][5];
int n;

int rec(int index,int bef)
{
    // cout << index << " " << bef << endl;
     if (index == 0)
    {
        cout << "YES\n";
        for (int i = 1 ; i <= n ; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        exit(0);
    }
    // cout << index << " " << bef << " " << dp[index][bef] << endl;
    if (dp[index][bef] != -1) return dp[index][bef];
    int ret = 0;
    for (int i = 0 ; i <= 3 ; i++)
    {
        int aa = i | bef;
        int bb = i & bef;
        // if (index == 1)
        // {
        //     cout << bef << " " << aa << " " << bb << endl;
        // }
        if (aa == a[index] && bb == b[index])
        {
            ans[index] = i;
            // cout << index << " " << i << endl;
            ret |= rec(index - 1,i);
        }
    }
    return dp[index][bef] = ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1 ; i < n ; i++) cin >> a[i];
    for (int i = 1 ; i < n ; i++) cin >> b[i];
    memset(dp,-1,sizeof(dp));
    for (int i = 0 ; i <= 3 ; i++)
        for (int j = 0 ; j <= 3 ; j++)
        {
            int kanan = j;
            int kiri = i;
            if (((kiri | kanan) == a[n - 1]) && ((kiri & kanan) == b[n - 1]))
            {
                // cout << i << " " << j << " " << (kiri | kanan) << " " << (kiri & kanan) << endl;
                ans[n - 1] = kiri;
                ans[n] = kanan;
                rec(n - 2,kiri);
                // return 0;
            }
        }
    cout << "NO\n";
    return 0;
}