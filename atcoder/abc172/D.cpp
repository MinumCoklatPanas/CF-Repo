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

ll tab[10000010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (ll i = 1 ; i <= 10000000 ; i++)
    {
        for (ll j = i ; j <= 10000000 ; j += i)
            tab[j]++;
    }
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1 ; i <= n ; i++)
        ans += i * tab[i];
    cout << ans << endl;
    return 0;
}