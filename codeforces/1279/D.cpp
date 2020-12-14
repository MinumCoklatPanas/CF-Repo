#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
#define int long long
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 998244353 ;
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

vector<int> tab[1000010];
int cnt[1000010];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        int k;
        cin >> k;
        for (int j = 1 ; j <= k ; j++)
        {
            int ta;
            cin >> ta;
            cnt[ta]++;
            tab[i].push_back(ta);
        }
    }
    int ans = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        int sz = tab[i].size();
        for (auto it : tab[i])
        {
            int prob = bagi(1ll,mul(n,sz));
            int choose = bagi(cnt[it],n);
            // cout << mul(n,sz) << " " << cnt[it] << " " << n << endl;
            int tot = mul(prob,choose);
            ans = add(ans,tot);
        }
    }
    cout << ans << endl;
    return 0;
}