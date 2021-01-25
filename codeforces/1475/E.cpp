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

int fak[1010];

int comb(int x,int y)
{
    int atas = fak[x];
    int bawah = mul(fak[y],fak[x - y]);
    return bagi(atas,bawah);
}

void solve()
{
    int n,k;
    cin >> n >> k;
    vector<int> tab(n);
    vector<int> frek(n + 5,0);
    for (auto &it : tab) cin >> it,frek[it]++;
    sort(tab.begin(),tab.end());
    reverse(tab.begin(),tab.end());
    int cnt = 0;
    for (int i = k - 1 ; i >= 0 ; i--)
    {
        if (tab[i] == tab[k - 1]) ++cnt;
        else break;
    }
    int ans = comb(frek[tab[k - 1]],cnt);
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fak[0] = 1;
    for (int i = 1 ; i <= 1000 ; i++) fak[i] = mul(fak[i - 1],i);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }    
    return 0;
}