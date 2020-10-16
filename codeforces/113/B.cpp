#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
const int PRIME = 137;
typedef pair<int,int> Hash;

const pair<int,int> HashMod = {1e9+7, 1e9+9};

ostream& operator<< (ostream& out,Hash h)
{
    out << "(" << h.first << "," << h.second << ")";
    return out;
}

int mul(int x,int y,int m)
{
    return ((x % m) * (y % m)) % m;
}

int add(int x,int y,int m)
{
    return ((x % m) + (y % m)) % m;
}

Hash add(Hash x,Hash y)
{
    Hash ret;
    ret.first = add(x.first,y.first,HashMod.first);
    ret.second = add(x.second,y.second,HashMod.second);
    return ret;
}

int sub(int x,int y,int m)
{
    int ret = ((x % m) - (y % m)) % m;
    if (ret < 0)
        ret += m;
    return ret;
}

Hash sub(Hash x,Hash y)
{
    Hash ret;
    ret.first = sub(x.first,y.first,HashMod.first);
    ret.second = sub(x.second,y.second,HashMod.second);
    return ret;
}

int modpow(int x,int y,int m)
{
    if (!y) return 1;
    int z = modpow(x,y / 2,m);
    z = mul(z,z,m);
    if (y & 1) z = mul(z,x,m);
    return z;
}

int inv(int x,int m)
{
    return modpow(x,m - 2,m);
}

int bagi(int x,int y,int m)
{
    return mul(x,inv(y,m),m);
}

Hash hashVal[4][2010];
Hash pan[2010];
Hash rev[2010];

void prec()
{
    pan[0].first = pan[0].second = 1;
    rev[0].first = rev[0].second = 1;
    for (int i = 1 ; i <= 2000 ; i++)
    {
        pan[i].first = mul(pan[i - 1].first,PRIME,HashMod.first);
        pan[i].second = mul(pan[i - 1].second,PRIME,HashMod.second);
        rev[i].first = bagi(1ll,pan[i].first,HashMod.first);
        rev[i].second = bagi(1ll,pan[i].second,HashMod.second);
    }
}

void generateHash(string s,int kode)
{
    Hash pengali = {1,1};
    for (int i = 0 ; i < s.length() ; i++)
    {
        int ix = s[i] - 'a' + 1;
        hashVal[kode][i].first = mul(ix,pengali.first,HashMod.first);
        hashVal[kode][i].second = mul(ix,pengali.second,HashMod.second);
        if (i > 0)
            hashVal[kode][i] = add(hashVal[kode][i],hashVal[kode][i - 1]);
        pengali.first = mul(pengali.first,PRIME,HashMod.first);
        pengali.second = mul(pengali.second,PRIME,HashMod.second);
        // cout << hashVal[kode][i] << " ";
        // cout << hashVal[kode][i] << " ";
    }
    // cout << endl;
    // cout << endl;
}

Hash getHash(int l,int r,int kode)
{
    Hash sum = (l == 0 ? hashVal[kode][r] : sub(hashVal[kode][r],hashVal[kode][l - 1]));
    // cout << sum << endl;
    // cout << rev[l] << endl;
    sum.first = mul(sum.first,rev[l].first,HashMod.first);
    sum.second = mul(sum.second,rev[l].second,HashMod.second);
    return sum;
}

int pref[2010];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    prec();
    string a,b,c;
    cin >> a >> b >> c;
    generateHash(a,0);
    // return 0;
    generateHash(b,1);
    generateHash(c,2);
    // cout << getHash(1,2,0) << endl;
    // return 0;
    vector<Hash> st;
    for (int i = 0 ; i < a.length() ; i++)
    {
        for (int j = i ; j < a.length() ; j++) if (j - i + 1 >= max(b.length(),c.length()))
        {
            Hash frontHash = getHash(i,i + b.length() - 1,0);
            Hash backHash = getHash(j - c.length() + 1,j,0);
            // cout << i << " " << j << " " << frontHash << " " << backHash << endl;
            if (frontHash == hashVal[1][b.length() - 1] && backHash == hashVal[2][c.length() - 1])
            {
                Hash partHash = getHash(i,j,0);
                // int bef = st.size();
                st.push_back(partHash);
                // if (st.size() != bef)
                //     cout << i << " " << j << endl;
            }
        }
    }
    sort(st.begin(),st.end());
    int ans = (st.size() > 0);
    for (int i = 1 ; i < st.size() ; i++)
    {
        ans += st[i] != st[i - 1];
    }
    cout << ans << endl;
    // cout << st.size() << endl;
    return 0;
}