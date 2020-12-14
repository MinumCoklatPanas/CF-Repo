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

int fak[200010];

int komb(int n,int r)
{
    assert(n >= r);
    int atas = fak[n];
    int bawah = mul(fak[r],fak[n - r]);
    return bagi(atas,bawah);
}

int bf(int n,int m)
{
    int ans = 0;
    for (int pos = 2 ; pos < n ; pos++)
    {
        int sumThisPos = 0;
        for (int pivot = n - 1 ; pivot <= m ; pivot++)
        {
            int kiri = pos - 1;
            int kanan = n - pos;
            int hitung_kiri = komb(pivot - 1,kiri);
            int sisa = (pivot - 1) - kiri;
            int hitung_kanan = komb(sisa,kanan - 1);
            int cnt = mul(hitung_kiri,mul(kiri,hitung_kanan));
            cerr << pivot << " " << cnt << endl;
            sumThisPos = add(cnt,sumThisPos);
        }
        cerr << endl;
        cerr << pos << " " << sumThisPos << endl;
        cerr << "--------------------------------\n";
        ans = add(ans,sumThisPos);
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fak[0] = 1;
    for (int i = 1 ; i <= 200000 ; i++) fak[i] = mul(fak[i - 1],i);
    int n,m;
    cin >> n >> m;
    if (n == 2)
    {
        cout << 0 << endl;
        return 0;
    }
    int ans = komb(m,n - 1);
    ans = mul(ans,n - 2);
    ans = mul(ans,modpow(2,n - 3));
    cout << ans << endl;
    return 0;
}