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

bool cek(ll k, ll n)
{
    if (k == 1) return 0;
    while (n % k == 0)
        n /= k;
    return (n % k == 1);
}

bool cek2(ll k,ll n)
{
    // cout << k << " " << n << endl;
    if (n == 1) return 1;
    if (n % k == 0)
        return cek2(k,n / k);
    else
    if (n > k)
        return cek2(k,n - k);
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    // for (ll i = 2 ; i <= n ; i++)
    // {
    //     if (cek2(i,n) && (n % i == 0))
    //         cout << i << endl;
    // }
    ll ans = 0;
    // cout << cek(3,n) << endl;
    for (ll i = 1 ; i * i < n ; i++) if ((n - 1) % i == 0)
    {
        if (i > 1)
            ans++;
        if (i * i != n - 1)
            ans++;
    }
    // cout << ans << endl;
    for (ll i = 1 ; i * i <= n ; i++) if (n % i == 0)
    {
        ans += cek(i,n);
        if (i * i != n)
            ans += cek(n / i,n);
    }
    // cout << ans << endl;
    cout << ans << endl;
    return 0;
}