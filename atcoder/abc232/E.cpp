#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const long long MOD = 998244353;
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
    else
        return 1;
}

template <long long MOD>
class ModInt
{
public:
    int v;

    ModInt() : v(0) {}
    ModInt(long long _v)
    {
        v = int((-MOD < _v && _v < MOD) ? (_v) : (_v % MOD));
        if (v < 0)
            v += MOD;
    }

    friend bool operator==(const ModInt &a, const ModInt &b)
    {
        return a.v == b.v;
    }
    friend bool operator!=(const ModInt &a, const ModInt &b)
    {
        return a.v != b.v;
    }
    friend bool operator<(const ModInt &a, const ModInt &b)
    {
        return a.v < b.v;
    }
    friend bool operator<=(const ModInt &a, const ModInt &b)
    {
        return a.v <= b.v;
    }
    friend bool operator>(const ModInt &a, const ModInt &b)
    {
        return a.v > b.v;
    }
    friend bool operator>=(const ModInt &a, const ModInt &b)
    {
        return a.v >= b.v;
    }

    ModInt &operator+=(const ModInt &a)
    {
        if ((v += a.v) >= MOD)
            v -= MOD;
        return *this;
    }
    ModInt &operator-=(const ModInt &a)
    {
        if ((v -= a.v) < 0)
            v += MOD;
        return *this;
    }
    ModInt &operator*=(const ModInt &a)
    {
        v = 1ll * v * a.v % MOD;
        return *this;
    }
    ModInt &operator/=(const ModInt &a)
    {
        return (*this) *= inverse(a);
    }

    friend ModInt pow(ModInt a, long long x)
    {
        ModInt res = 1;
        assert(x >= 0);
        for (; x; x /= 2, a *= a)
            if (x & 1)
                res *= a;
        return res;
    }
    friend ModInt inverse(ModInt a)
    {
        assert(a.v != 0);
        return pow(a, MOD - 2);
    }

    ModInt operator+() const
    {
        return ModInt(v);
    }
    ModInt operator-() const
    {
        return ModInt(-v);
    }
    ModInt operator++() const
    {
        return *this += 1;
    }
    ModInt operator--() const
    {
        return *this -= 1;
    }

    friend ModInt operator+(ModInt a, const ModInt &b)
    {
        return a += b;
    }
    friend ModInt operator-(ModInt a, const ModInt &b)
    {
        return a -= b;
    }
    friend ModInt operator*(ModInt a, const ModInt &b)
    {
        return a *= b;
    }
    friend ModInt operator/(ModInt a, const ModInt &b)
    {
        return a /= b;
    }

    friend istream &operator>>(istream &is, ModInt &v)
    {
        is >> v.v;
        return is;
    }
    friend ostream &operator<<(ostream &os, const ModInt &v)
    {
        os << v.v;
        return os;
    }
};

using Mint = ModInt<MOD>;

Mint dp[1000010][2][2]; //[step][rownya sama][columnya sama]

void solve()
{
    Mint n,m,k;
    cin >> n >> m >> k;
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    dp[0][(x1 == x2)][(y1 == y2)] = 1;
    for (int i = 1 ; i <= k.v ; i++)
    {
        dp[i][0][0] = (n - 1) * dp[i - 1][1][0] + (m - 1) * dp[i - 1][0][1] + (n + m - 4) * dp[i - 1][0][0];
        dp[i][0][1] = (n - 2) * dp[i - 1][0][1] + dp[i - 1][0][0] + (n - 1) * dp[i - 1][1][1];
        dp[i][1][0] = (m - 2) * dp[i - 1][1][0] + dp[i - 1][0][0] + (m - 1) * dp[i - 1][1][1];
        dp[i][1][1] = dp[i - 1][0][1] + dp[i - 1][1][0];
        // cerr << dp[i][0][0] << " " << dp[i][0][1] << " " << dp[i][1][0] << " " << dp[i][1][1] << endl;
    }
    cout << dp[k.v][1][1] << endl;
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