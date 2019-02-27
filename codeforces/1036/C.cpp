#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MOD = 1e9 + 7;
const ll MAXN = 1e3;

ll readInt ()
{
    bool minus = false;
    ll result = 0;
    char ch;
    ch = getchar();
    while (true)
    {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true;
    else result = ch-'0';
    while (true)
    {
        ch = getchar();
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
    if (NN == 0) { putchar('0');  return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (NN != 0) { rev = (rev<<3) + (rev<<1) + NN % 10; NN /= 10;}  //store reverse of N in rev
    while (rev != 0) { putchar(rev % 10 + '0'); rev /= 10;}
    while (count--) putchar('0');
}

//[digit_ke][non_zero][flag]
ll DP[20][5][2];

ll rec(ll digit_ke,ll non_zero,ll flag,vector<ll> &angka)
{
    if (non_zero > 3) return 0;
    if (digit_ke == angka.size()) return 1;
    if (DP[digit_ke][non_zero][flag] != -1) return DP[digit_ke][non_zero][flag];

    ll ret = 0;
    if (flag)
    {
        ret += rec(digit_ke + 1,non_zero + (angka[digit_ke] != 0),1,angka);
        for (ll i = 0 ; i < angka[digit_ke] ; i++)
            ret += rec(digit_ke + 1,non_zero + (i != 0),0,angka);
    }
    else
    {
        for (ll i = 0 ; i < 10 ; i++)
            ret += rec(digit_ke + 1,non_zero + (i != 0),0,angka);   
    }
    return DP[digit_ke][non_zero][flag] = ret;
}

ll hitung(ll k)
{
    vector<ll> angka;
    while (k)
    {
        angka.push_back(k % 10);
        k  /= 10;
    }
    reverse(angka.begin(),angka.end());
    memset(DP,-1,sizeof(DP));
    return rec(0,0,1,angka);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll l,r;
        cin >> l >> r;
        ll ans = hitung(r) - hitung(l - 1);
        cout << ans << endl;
    }
}