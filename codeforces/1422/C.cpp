#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
#define int ll
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

int fak[100010];
int inverse[100010];
int fak_inv[100010];
int pan[100010];

void prec()
{
    inverse[1] = 1;
    fak[1] = 1;
    fak[0] = 1;
    pan[1] = 2;
    pan[0] = 1;
    for (int i = 2 ; i <= 100000 ; i++)
    {
        inverse[i] = mul((MOD - (MOD / i)),inverse[MOD % i]);
        fak[i] = mul(fak[i - 1], i);
        pan[i] = mul(pan[i - 1],2ll);
    }
    fak_inv[0] = fak_inv[1] = 1;
    for (int i = 2 ; i <= 100000 ; i++)
        fak_inv[i] = mul(inverse[i], fak_inv[i - 1]);
}

int comb(int x,int y)
{
    if (y == x || y == 0) return 1;
    int ret = fak[x];
    ret = mul(ret,fak_inv[x - y]);
    ret = mul(ret,fak_inv[y]);
    return ret;
}

int bf(string s)
{
    reverse(s.begin(), s.end());
    int ret = 0;
    for (int i = 0 ; i < s.length() ; i++)
    {
        for (int j = i ; j < s.length() ; j++)
        {
            string tmp = "";
            for (int k = 0 ; k < i ; k++)
                tmp += s[k];
            for (int k = j + 1 ; k < s.length() ; k++)
                tmp += s[k]; 
            stringstream ss(tmp);
            cout << tmp << endl;
            int a;
            ss >> a;
            ret += a;
        }
    }
    return ret;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    prec();
    reverse(s.begin(),s.end());
    int sum = 0;
    int pengali = 1;
    int ans = 0;
    for (int i = 0 ; i < s.length() ; i++)
    {
        // sum = add(sum,pengali);
        int rem = s.length() - i;
        int tmp = mul(1ll,(s[i] - '0'));
        // cout << s[i] << " " << tmp << " " << sum << endl;
        ans = add(ans,mul(tmp,sum));
        // sum = sub(sum,pengali);
        sum = add(sum,mul(i + 1,pengali));
        pengali = mul(pengali,10ll);
    }
    
    // pengali = bagi(pengali,10ll);
    // ans = sub(ans,mul(pengali,(s.back() - '0')));
    pengali = 1;
    for (int i = 0 ; i < s.length() ; i++)
    {
        int rem = s.length() - i;
        int tmp = mul(comb(rem,2ll),(s[i] - '0'));
        tmp = mul(tmp,pengali);
        // cout << s[i] << " " << tmp << endl;
        ans = add(ans,tmp);
        pengali = mul(pengali, 10ll);
    }
    // ans = add(ans, (s[0] - '0'));
    cout << ans << "\n";
    return 0;
}