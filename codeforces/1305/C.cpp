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

ll readll ()
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

ll frek[1010];
ll tab[1010];

int main()
{
    ll n = readll(),m = readll();
    if (n > m)
    {
        puts("0");
        // cout << 0 << endl;
        return 0;
    }
    for (ll i = 1 ; i <= n ; i++)
    {
        ll ta;
        // cin >> ta;
        ta = readll();
        frek[ta % m]++;
        if (frek[ta % m] > 1)
        {
            puts("0");
            return 0;
        }
        tab[i] = ta;
    }
    ll ans = 1;
    for (ll i = 1 ; i <= n ; i++)
        for (ll j = 1 ; j < i ; j++)
        {
            ans *= abs(tab[i] - tab[j]);
            ans %= m;
            if (ans == 0)
            {
                puts("0");
                return 0;
            }
        }
    // ans %= m;
    printf("%d\n",ans);
    // cout << ans << endl;
    return 0;
}