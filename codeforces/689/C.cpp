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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll cnt(ll x)
{
    ll ret = 0;
    for (ll i = 2 ; i * i * i <= x ; i++)
    {
        ll has = x / (i * i * i);
        ret += has;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll l = 1;
    ll r = 1e18;
    while (r - l > 1)
    {
        ll mid = (l + r) >> 1;
        ll tmp = cnt(mid);
        if (tmp >= n)
            r = mid;
        else
            l = mid + 1;
    }
    if (cnt(l) == n)
        cout << l << endl;
    else
    if (cnt(r) == n)
        cout << r << endl;
    else
        cout << "-1\n";
    return 0;
}