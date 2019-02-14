#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MOD = 1e9 + 7;
const ll MAXN = 1e3;

inline int readInt ()
{
    bool minus = false;
    int result = 0;
    char ch;
    ch = _getchar_nolock();
    while (true)
    {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = _getchar_nolock();
    }
    if (ch == '-') minus = true;
    else result = ch-'0';
    while (true)
    {
        ch = _getchar_nolock();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}


inline void writeInt (ll n)
{
    ll NN = n, rev, count = 0;
    rev = NN;
    if (NN == 0) { _putchar_nolock('0');  return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (NN != 0) { rev = (rev<<3) + (rev<<1) + NN % 10; NN /= 10;}  //store reverse of N in rev
    while (rev != 0) { _putchar_nolock(rev % 10 + '0'); rev /= 10;}
    while (count--) _putchar_nolock('0');
}

struct query
{
    int L;
    int R;
    int ix;
};

query ask[200010];
int frek[1000010];
int tab[200010];
ll ans[200010];
int blk = 375;
int n,m;

inline ll cei(ll x,ll y)
{
    return (x / y) + (x % y != 0);
}

inline bool cmp(query a,query b)
{
    ll kiri = cei(a.L,blk);
    ll kanan = cei(b.L,blk);
    if (kiri == kanan)
        return a.R < b.R;
    return kiri < kanan;
}

inline void update(ll ix,ll &tot,ll val)
{
    tot -= 1ll * frek[ix] * frek[ix] * ix;
    frek[ix] += val;
    tot += 1ll * frek[ix] * frek[ix] * ix;
    return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    n = readInt(); m = readInt();
    for (int i = 1 ; i <= n ; i++)
        tab[i] = readInt();
    for (int i = 1 ; i <= m ; i++)
    {
        ask[i].L = readInt();
        ask[i].R = readInt();
        ask[i].ix = i;
    }
    sort(ask + 1,ask + m + 1,cmp);
    ll tot = 0ll;
    int CurrL = 1;
    int CurrR = 1;
    for (int i = 1 ; i <= m ; i++)
    {
        ll L = ask[i].L; ll R = ask[i].R;
        while (CurrL > L)
        {
            update(tab[CurrL - 1],tot,1);
            --CurrL;
        }
        while (CurrR <= R)
        {
            update(tab[CurrR],tot,1);
            ++CurrR;
        }
        while (CurrL < L)
        {
            update(tab[CurrL],tot,-1);
            ++CurrL;
        }
        while (CurrR > R + 1)
        {
            update(tab[CurrR - 1],tot,-1);
            --CurrR;
        }
        ans[ask[i].ix] = tot;
    }
    for (ll i = 1 ; i <= m ; i++)
    {
        writeInt(ans[i]);
        puts("");
    }
}