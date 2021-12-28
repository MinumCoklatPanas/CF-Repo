#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
// #define int long long
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 998244353;
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
    int n,k;
    cin >> n >> k;
    if (k == 0)
    {
        cout << 1 << endl;
        return;
    }
    string s;
    cin >> s;
    vector<vector<Mint>> dp(n,vector<Mint>(n,0));
    vector<Mint> fak(n + 5),ifak(n + 5);
    fak[0] = 1;
    ifak[0] = 1;
    for (int i = 1 ; i <= n ; i++) 
    {
        fak[i] = fak[i - 1] * Mint(i);
        ifak[i] = Mint(1) / fak[i];
    }
    const auto comb = [&](int x,int y) -> Mint
    {
        if (x < y) return Mint(0);
        return fak[x] * ifak[x - y] * ifak[y];
    };
    vector<int> pref(n,0);
    pref[0] = s[0] - '0';
    for (int i = 1 ; i < n ; i++) pref[i] = pref[i - 1] + (s[i] - '0');
    if (pref[n - 1] < k)
    {
        cout << 1 << endl;
        return;
    }
    Mint ans = 1;
    for (int i = 0 ; i < n ; i++)
        for (int j = i + 1 ; j < n ; j++)
        {
            int len = j - i + 1;
            int cnt1 = pref[j] - (i == 0 ? 0 : pref[i - 1]);
            if (cnt1 > k) continue;
            int cnt0 = len - cnt1;
            if (s[i] == '0') --cnt1;
            else --cnt0;
            if (s[j] == '0') --cnt1;
            else --cnt0;
            if (cnt1 >= 0)
                ans += comb(len - 2,cnt1);
        }
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