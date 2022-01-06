#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
// #define int long long
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
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

template <int MOD>
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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<Mint>> CurDP(n + 5, vector<Mint>(n + 5, 0)); //[angka di A][angka di B]
    const auto Build = [](vector<vector<Mint>> &dp, int n) -> void
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] += dp[i][j - 1];
                dp[i][j] -= dp[i - 1][j - 1];
            }
    };
    const auto Get = [](vector<vector<Mint>> &dp, int x1, int y1, int x2, int y2) -> Mint
    {
        Mint ret = dp[x2][y2];
        ret -= dp[x1 - 1][y2];
        ret -= dp[x2][y1 - 1];
        ret += dp[x1 - 1][y1 - 1];
        return ret;
    };
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            CurDP[i][j] = (i <= j);
            // cerr << CurDP[i][j] << " ";
        }
        // cerr << endl;
    }
    if (m != 1)
        Build(CurDP,n);
    // cerr << endl;
    for (int i = 2 ; i <= m ; i++)
    {
        vector<vector<Mint>> NewDP(n + 5,vector<Mint>(n + 5,0));
        //dp[i][j] = sum(i' = i to N) sum(j' = 1 to j) dp[i'][j']
        for (int j = 1 ; j <= n ; j++)
        {
            for (int k = 1 ; k <= n ; k++)
            {
                NewDP[j][k] = Get(CurDP,j,1,n,k);
                // cerr << NewDP[j][k] << " ";
            }
            // cerr << endl;
        }
        CurDP = NewDP;
        if (i != m)
            Build(CurDP,n);
    }
    Mint ans = 0;
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= n ; j++)
            ans += CurDP[i][j];
    cout << ans << endl;
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