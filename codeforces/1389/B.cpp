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

ll dp[2][7][100010]; //[dari kiri/kanan][cnt kiri][indeks]
ll tab[100010];
ll n,k,z;

ll rec(ll from,ll cntKiri,ll indeks)
{
    ll cntStep = 0;
    if (!from)
    {
        cntStep += indeks - 1;
        cntStep += (cntKiri) * 2;
    }
    else
    {
        cntStep = indeks;
        cntStep += (cntKiri - 1) * 2;
        cntStep++;
    }
    if (cntStep > k) return 0;
    if (indeks > n) return -INFF;
    if (dp[from][cntKiri][indeks] != -1) return dp[from][cntKiri][indeks];
    ll ret = 0;
    if (from == 1)
    {
        ret = rec(0,cntKiri,indeks + 1);
    }
    else
    {
        if (cntKiri < z)
            ret = rec(1,cntKiri + 1,indeks - 1);
        ret = max(ret,rec(0,cntKiri,indeks + 1));
    }
    return dp[from][cntKiri][indeks] = ret + tab[indeks];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> z;
        for (ll i = 1 ; i <= n ; i++)
        {
            cin >> tab[i];
            for (ll j = 0 ; j <= 5 ; j++)
                dp[0][j][i] = dp[1][j][i] = -1;
        }
        ll ans = rec(1,0,1);
        cout << ans << endl;
    }
    return 0;
}