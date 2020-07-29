#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
const ll PRIME = 137;

ll mul(ll x,ll y)
{
    return ((x % MOD) * (y % MOD)) % MOD;
}

ll add(ll x,ll y)
{
    return ((x % MOD) + (y % MOD)) % MOD;
}

ll sub(ll x,ll y)
{
    ll ret = ((x % MOD) - (y % MOD)) % MOD;
    if (ret < 0)
        ret += MOD;
    return ret;
}

ll modpow(ll x,ll y)
{
    if (!y) return 1;
    ll z = modpow(x,y / 2);
    z = mul(z,z);
    if (y & 1) z = mul(z,x);
    return z;
}

ll inv(ll x)
{
    return modpow(x,MOD - 2);
}

ll bagi(ll x,ll y)
{
    return mul(x,inv(y));
}

ll hashVal[2][200010];
char a[200010],b[200010];
ll pangkat[200010];
ll inverse[200010];

void prec()
{
    pangkat[0] = 1;
    inverse[0] = 1;
    for (ll i = 1 ; i <= 200000 ; i++)
    {
        pangkat[i] = mul(pangkat[i - 1],PRIME);
        inverse[i] = inv(pangkat[i]);
    }
}

ll getHash(int l,int r,int kode)
{
    ll tmp = sub(hashVal[kode][r],(l > 0 ? hashVal[kode][l - 1] : 0ll));
    // cout << hashVal[kode][r] << " " << hashVal[kode][l - 1] << endl;
    tmp = mul(tmp,inverse[l]);
    return tmp;
}

bool rec(int l_A,int r_A,int l_B,int r_B)
{
    int len = r_A - l_A + 1;
    if (len % 2 == 1)
    {
        return (getHash(l_A,r_A,0) == getHash(l_B,r_B,1));
    }
    if (getHash(l_A,r_A,0) == getHash(l_B,r_B,1))
    {
        // cout << l_A << " " << r_A << " " << l_B << " " << r_B << endl; 
        return 1;
    }
    int mid_A = l_A + (len / 2) - 1;
    int mid_B = l_B + (len / 2) - 1;
    return (rec(l_A,mid_A,mid_B + 1,r_B) && rec(mid_A + 1,r_A,l_B,mid_B)) ||
           (rec(l_A,mid_A,l_B,mid_B) && rec(mid_A + 1,r_A,mid_B + 1,r_B));
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    // srand(time(NULL));
    // auto mulai = clock();
    prec();
    scanf("%s %s",a,b);
    // if (a.length() % 2 == 1)
    // {
    //     if (a == b)
    //         cout << "YES\n";
    //     else
    //         cout << "NO\n";
    //     return 0;
    // }
    int n = strlen(a);
    for (int i = 0 ; i < n ; i++)
    {
        int ixA = a[i] - 'a' + 1;
        int ixB = b[i] - 'a' + 1;
        // ll ixA = 1;
        // ll ixB = 2;
        if (i > 0)
        {
            hashVal[0][i] = add(hashVal[0][i - 1],mul(ixA,pangkat[i]));
            hashVal[1][i] = add(hashVal[1][i - 1],mul(ixB,pangkat[i]));
        }
        else
        {
            hashVal[0][i] = ixA;
            hashVal[1][i] = ixB;
        }
        // cout << "(" << hashVal[0][i] << "," << hashVal[1][i] << ") ";
    }
    // cout << endl;
    // cout << getHash(2,3,1) << endl;
    // return 0;
    if (rec(0,n - 1,0,n - 1))
        puts("YES");
    else
        puts("NO");
    // auto akhir = clock();
    // double rt = (double) (akhir - mulai) / (double) CLOCKS_PER_SEC;
    // cout << rt << endl;
    return 0;
}