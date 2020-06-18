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

map<ll,ll> mp;

int tab[4010][4010];

int sum(int a,int b,int c,int d)
{
    int ret = 0;
    for (int i = a ; i <= b ; i++)
        for (int j = c ; j <= d ; j++)
            ret += tab[i][j];
    return ret;
}

void bf(string s,int n)
{
    for (int i = 0 ; i < s.length() ; i++)
        for (int j = 0 ; j < s.length() ; j++)
            tab[i][j] = (s[i] - '0') * (s[j] -'0');
    int ret = 0;
    for (int a = 0 ; a < s.length() ; a++)
        for (int b = a ; b < s.length() ; b++)
            for (int c = 0 ; c < s.length() ; c++)
                for (int d = c ; d < s.length() ; d++)
                    if (sum(a,b,c,d) == n)
                    {
                        // cout << a << " " << b << " " << c << " " << d << endl;
                        ++ret;
                    }
    cout << ret << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    string s;
    cin >> s;
    for (ll i = 0 ; i < s.length() ; i++)
    {
        ll sum = 0;
        for (ll j = i ; j < s.length() ; j++)
        {
            sum += (s[j] - '0');
            // cout << sum << endl;
            mp[sum]++;
        }
    }
    // bf(s,n);
    if (n == 0)
    {
        ll tmp = (s.length() * (s.length() + 1)) / 2;
        ll ans = mp[0] * tmp * 2;
        ans -= mp[0] * mp[0];
        cout << ans << endl;
        return 0;
    }
    ll ans = 0;
    for (ll i = 1 ; i * i <= n ; i++) if (n % i == 0)
    {
        ll rem = n / i;
        if (rem == i)
        {
            ans += (mp[rem]) * (mp[i]);
        }
        else
        {
            ans += 2 * (mp[rem]) * (mp[i]);
        }
    }
    cout << ans << endl;
    return 0;
}