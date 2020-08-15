#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

ll tab[3010][3010];
ll dp[3010][3010][5]; // [r][c][rem]
ll n,m,k;

ll rec(ll r,ll c,ll rem)
{
    if (r > n) return 0;
    if (c > m) return 0;
    if (r == n && c == m) return tab[r][c] * (rem > 0);
    if (dp[r][c][rem] != -1) return dp[r][c][rem];
    ll ret = 0;
    // cout << r << " " << c << " " << rem << endl;
    ret = max(ret,rec(r,c + 1,rem));
    if (rem == 0)
    {
        ret = max(ret,rec(r + 1,c,3));
    }
    else
    {
        ret = max(ret,tab[r][c] + rec(r,c + 1,rem - 1));
        ret = max(ret,tab[r][c] + rec(r + 1,c,3));
    }
    // cout << r << " " << c << " " << rem << ": " << ret << endl;
    return dp[r][c][rem] = ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dp,-1,sizeof(dp));
    cin >> n >> m >> k;
    for (ll i = 1 ; i <= k ; i++)
    {
        ll r,c,v;
        cin >> r >> c >> v;
        tab[r][c] = v;
    }
    ll ans = rec(1,1,3);
    cout << ans << endl;
    return 0;
}