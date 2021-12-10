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

map<int,vector<int>> x,y;
set<pair<int,int>> visited;
set<int> cntX,cntY;
pair<int,int> tab[100010];
int cntVertex,cntEdge;

void dfs(int xx,int yy)
{
    if (visited.find({xx,yy}) != visited.end()) return;
    // cerr << "yo\n";
    ++cntVertex;
    visited.insert({xx,yy});
    cntX.insert(xx);
    cntY.insert(yy);
    //atas
    auto itY = upper_bound(x[xx].begin(),x[xx].end(),yy);
    if (itY != x[xx].end())
    {
        ++cntEdge;
        dfs(xx,*itY);
    }

    //bawah
    itY = lower_bound(x[xx].begin(),x[xx].end(),yy);
    if (itY != x[xx].begin())
    {
        --itY;
        ++cntEdge;
        dfs(xx,*itY);
    }

    //kanan
    auto itX = upper_bound(y[yy].begin(),y[yy].end(),xx);
    if (itX != y[yy].end())
    {
        ++cntEdge;
        dfs(*itX,yy);
    }

    //kiri
    itX = lower_bound(y[yy].begin(),y[yy].end(),xx);
    if (itX != y[yy].begin())
    {
        --itX;
        ++cntEdge;
        dfs(*itX,yy);
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        int a,b;
        cin >> a >> b;
        x[a].push_back(b);
        y[b].push_back(a);
        tab[i] = {a,b};
    }
    // return;
    for (auto &it : x)
    {
        sort(it.second.begin(),it.second.end());
    }
    for (auto &it : y)
    {
        sort(it.second.begin(),it.second.end());
    }
    Mint ans = 1;
    sort(tab + 1,tab + n + 1);
    // for (int i = 1 ; i <= n ; i++)
    //     cerr << tab[i].first << " " << tab[i].second << endl;
    for (int i = 1 ; i <= n ; i++) if (visited.find(tab[i]) == visited.end())
    {
        cntX.clear(); cntY.clear();
        cntVertex = 0,cntEdge = 0;
        dfs(tab[i].first,tab[i].second);
        cntEdge /= 2;
        Mint add = pow(Mint(2),cntX.size() + cntY.size());
        // cerr << cntVertex << " " << cntEdge << " " << i << endl;
        if (cntEdge == cntVertex - 1)
            add -= Mint(1);
        ans *= add;
        // cerr << cntX.size() << " " << cntY.size() << endl;
        // ans *= pow(Mint(2),cntX.size() + cntY.size());
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