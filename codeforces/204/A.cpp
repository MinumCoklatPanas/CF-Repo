#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

ll convert(string s)
{
    if (s.length() == 0) return 0;
    stringstream ss(s);
    ll ret;
    ss >> ret;
    return ret;
}

ll calc(ll dig,ll bound,ll len)
{
    string mini,maxi;
    mini += dig + '0';
    maxi += dig + '0';
    while (mini.length() + 1 < len)
    {
        mini += '0';
        maxi += '9';
    }
    if (len != 1)
    {
        mini += dig + '0';
        maxi += dig + '0';
    }
    ll mn = convert(mini);
    ll mx = convert(maxi);
    // cout << mn << " " << mx << endl;
    if (mn > bound) return 0;
    mx = min(mx,bound);
    maxi = to_string(mx);
    string asw;
    for (int i = 1 ; i + 1 < maxi.length() ; i++)
        asw += maxi[i];
    ll ret = convert(asw);
    return (maxi[0] <= maxi.back()) + ret;
}

bool valid(ll x)
{
    string tmp = to_string(x);
    return (tmp[0] == tmp.back());
}

ll bf(ll l,ll r)
{
    ll ret = 0;
    for (int i = l ; i <= r ; i++)
    {
        ret += valid(i);
        // if (valid(i))
        //     cout << i << endl;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(NULL));
    ll l,r;
    // cin >> l >> r;
    for (int i = 1 ; i <= 1 ; i++)
    {
        cin >> l >> r;
        // cout << bf(l,r) << endl;
        // // cout << calc(1,17236,5) << endl;
        // return 0;
        ll ans = 0;
        for (ll dig = 1 ; dig < 10 ; dig++)
            for (ll len = 1 ; len <= 18 ; len++)
            {
                ll a = calc(dig,r,len);
                ll b = calc(dig,l - 1,len);
                // cout << dig << " " << len << ": " << a << " " << b << endl;
                ans += a - b;
            }
        // if (ans != bf(l,r))
        //     cout << "FAILED " << l << " " << r<< endl;
        cout << ans << endl;
    }
    return 0;
}