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

ll tab[100010];
ll n;

bool cek(ll x)
{
    ll rem = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        if (tab[i] > x) return false;
        rem += x - tab[i];
    }
    return (rem >= x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll sum = 0;
    cin >> n;
    for (ll i = 1 ; i <= n ; i++)
    {
        cin >> tab[i];
        sum += tab[i];
    }
    ll l = 0;
    ll r = (ll)1e12;
    while (r - l > 1)
    {
        ll mid = (l + r) >> 1ll;
        if (cek(mid))
            r = mid;
        else
            l = mid + 1;
    }
    if (cek(l))
        cout << l << endl;
    else
        cout << r << endl;
    return 0;
}