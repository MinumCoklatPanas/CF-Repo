#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
#define int long long
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 998244353;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int mul(int x,int y)
{
    return ((x % MOD) * (y % MOD)) % MOD;
}

int add(int x,int y)
{
    return ((x % MOD) + (y % MOD)) % MOD;
}

int sub(int x,int y)
{
    int ret = ((x % MOD) - (y % MOD)) % MOD;
    if (ret < 0)
        ret += MOD;
    return ret;
}

int modpow(int x,int y)
{
    if (!y) return 1;
    int z = modpow(x,y / 2);
    z = mul(z,z);
    if (y & 1) z = mul(z,x);
    return z;
}

int inv(int x)
{
    return modpow(x,MOD - 2);
}

int bagi(int x,int y)
{
    return mul(x,inv(y));
}

int dp[410][410];
bool ada[410][410];
int fak[1010];
int n,m;

int rec(int l,int r)
{
    // cerr << l << " " << r << endl;
    if (l > r) return 1;
    if ((r - l + 1) % 2 == 1) return 0;
    if (r == l + 1)
    {
        return ada[l][r];
    }
    if (dp[l][r] != -1) return dp[l][r];
    int ret = 0;
    if (ada[l][r]) ret = add(ret,rec(l + 1,r - 1));
    for (int i = l ; i < r ; i++) if (ada[l][i])
    {
        int kiri = rec(l + 1,i - 1);
        int kanan = rec(i + 1,r);
        int lenKiri = (i - l + 1) / 2;
        int lenKanan = (r - i) / 2;
        int ways = bagi(fak[lenKanan + lenKiri],mul(fak[lenKanan],fak[lenKiri]));
        ret = add(ret,mul(ways,mul(kiri,kanan)));
    }
    return dp[l][r] = ret;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fak[0] = 1;
    for (int i = 1 ; i <= 1000 ; i++) fak[i] = mul(fak[i - 1],i);
    cin >> n >> m;
    for (int i = 0 ; i < m ; i++)
    {
        int x,y;
        cin >> x >> y;
        ada[x][y] = 1;
    }
    n *= 2;
    memset(dp,-1,sizeof(dp));
    int ans = rec(1,n);
    cout << ans << endl;
    return 0;
}