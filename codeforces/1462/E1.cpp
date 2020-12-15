#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
#define int long long
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 111111151111111;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int frek[200010];
int pref[200010];
int fak[200010];

int mul(int x,int y)
{
    return x * y;
}

int add(int x,int y)
{
    return x + y;
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

int komb(int x,int y)
{
    if (x < y) return 0;
    if (y == 0) return 1;
    int atas = 1;
    for (int i = 0 ; i < y ; i++) atas *= (x - i);
    int bawah = 1;
    for (int j = 1 ; j <= y ; j++) bawah *= j;
    return atas / bawah;
}

int get(int l,int r)
{
    if (l > r) return 0;
    return pref[r] - pref[l - 1];
}

void solve()
{
    int n,k,m;
    cin >> n;
    m = 3;
    k = 2;
    // cin >> n >> m >> k;
    for (int i = 1 ; i <= n ; i++) frek[i] = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        frek[ta]++;
    }
    for (int i = 1 ; i <= n ; i++)
    {
        pref[i] = pref[i - 1] + frek[i];
    }
    int ans = 0;
    for (int i = 1 ; i <= n ; i++) //ini maxnya
    {
        for (int j = 1 ; j <= min(m,frek[i]) ; j++) //ambil max
        {
            int rem = m - j;
            int cur = komb(frek[i],j);
            int cnt = get(max(1ll,i - k),i - 1);
            int ambil = komb(cnt,rem);
            cur = mul(cur,ambil);
            // cout << i << " " << j << " " << cur << " " << cnt << " " << rem << endl;
            ans = add(ans,cur);
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fak[0] = 1;
    for (int i = 1 ; i <= 200000 ; i++) fak[i] = mul(fak[i - 1],i);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}