#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
#define int long long
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
const int PRIME = 137;
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
    else return 1;
}

int add(int x,int y,int m)
{
    return ((x % m) + (y % m)) % m;
}

int sub(int x,int y,int m)
{
    int ret = ((x % m) - (y % m)) % m;
    if (ret < 0) ret += m;
    return ret;
}

int mul(int x,int y,int m)
{
    return ((x % m) * (y % m)) % m;
}

int modpow(int x,int y,int m)
{
    if (!y) return 1;
    int z = modpow(x,y / 2,m);
    z = mul(z,z,m);
    if (y & 1) z = mul(z,x,m);
    return z;
}

int inverse(int x,int m)
{
    return modpow(x,m - 2,m);
}

int bagi (int x,int y,int m)
{
    return mul(x,inverse(y,m),m);
}

struct hashVal
{
    int val1,val2;
    hashVal(){}
    hashVal(int v1,int v2)
    {
        val1 = v1;
        val2 = v2;
    }

    hashVal operator+(hashVal &other)
    {
        hashVal ret;
        ret.val1 = add(val1,other.val1,MOD);
        ret.val2 = add(val2,other.val2,MOD2);
        return ret;
    }

    hashVal operator-(hashVal &other)
    {
        hashVal ret;
        ret.val1 = sub(val1,other.val1,MOD);
        ret.val2 = sub(val2,other.val2,MOD2);
        return ret;
    }

    hashVal operator*(int x)
    {
        hashVal ret;
        ret.val1 = mul(val1,x,MOD);
        ret.val2 = mul(val2,x,MOD2);
        return ret;
    }

    hashVal operator*(hashVal &other)
    {
        hashVal ret;
        ret.val1 = mul(val1,other.val1,MOD);
        ret.val2 = mul(val2,other.val2,MOD2);
        return ret;
    }

    hashVal operator/(int x)
    {
        hashVal ret;
        ret.val1 = bagi(val1,x,MOD);
        ret.val2 = bagi(val2,x,MOD2);
        return ret;
    }

    hashVal operator/(hashVal &other)
    {
        hashVal ret;
        ret.val1 = bagi(val1,other.val1,MOD);
        ret.val2 = bagi(val2,other.val2,MOD2);
        return ret;
    }

    bool operator==(hashVal &other)
    {
        return (make_pair(val1,val2) == make_pair(other.val1,other.val2));
    }

    bool operator!=(hashVal &other)
    {
        return (make_pair(val1,val2) != make_pair(other.val1,other.val2));
    }
};


void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    bool sama = 1;
    for (int i = 0 ; i < n / 2 ; i++)
    {
        if (s[i] != s[0])
        {
            sama = 0;
            break;
        }
    }
    if (sama)
    {
        cout << "Impossible\n";
        return;
    }
    vector< hashVal > hashDepan(n),hashBelakang(n);
    vector< hashVal > pan(n);
    pan[0] = hashVal(1,1);

    for (int i = 1 ; i < n ; i++)
    {
        pan[i] = pan[i - 1] * PRIME;
    }

    const auto get = [&](char c) -> int
    {
        return c - 'a' + 1;
    };
    //hapus depan, taruh belakang

    hashDepan[0] = hashVal(get(s[0]),get(s[0]));
    for (int i = 1 ; i < n ; i++)
    {
        hashDepan[i] = hashVal(get(s[i]),get(s[i])) * pan[i];
        hashDepan[i] = hashDepan[i - 1] + hashDepan[i]; 
    }

    hashBelakang[n - 1] = hashVal(get(s[n - 1]),get(s[n - 1]));
    for (int i = n - 2 ; i >= 0 ; i--)
    {
        hashBelakang[i] = hashVal(get(s[i]),get(s[i])) * pan[(n - 1) - i];
        hashBelakang[i] = hashBelakang[i + 1] + hashBelakang[i];
    }


    //ambil depan taruh belakang
    for (int i = 0 ; i + 1 < n ; i++)
    {
        hashVal newHashDepan = hashDepan[n - 1] - hashDepan[i];
        newHashDepan = newHashDepan / pan[i + 1];
        hashVal tmp = (hashDepan[i] * pan[n - 1 - i]);
        newHashDepan = newHashDepan + tmp;

        hashVal newHashBelakang = hashBelakang[i + 1];
        hashVal sisa = hashBelakang[0] - newHashBelakang;
        newHashBelakang = newHashBelakang * pan[i + 1];
        tmp = sisa / pan[n - 1 - i];
        newHashBelakang = newHashBelakang + tmp;

        if (newHashDepan == newHashBelakang && newHashDepan != hashDepan[n - 1])
        {
            cout << 1 << endl;
            return;
        }
    }

    //ambil belakang taruh depan
    for (int i = n - 1 ; i > 0 ; i--)
    {
        hashVal newHashDepan = hashDepan[i - 1];
        hashVal sisa = hashDepan[n - 1] - newHashDepan;
        newHashDepan = newHashDepan * pan[n - i];
        hashVal tmp = sisa / pan[i];
        newHashDepan = newHashDepan + tmp;

        hashVal newHashBelakang = hashBelakang[0] - hashBelakang[i];   
        newHashBelakang = newHashBelakang / pan[n - i];
        tmp = hashBelakang[i] * pan[i];
        newHashBelakang = newHashBelakang + tmp;

        if (newHashDepan == newHashBelakang && newHashDepan != hashDepan[n - 1])
        {
            cout << 1 << endl;
            return;
        }    
    }

    cout << 2 << endl;
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