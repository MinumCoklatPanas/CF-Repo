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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll k,b,n,t;
    cin >> k >> b >> n >> t;
    if (k == 1)
    {
        double kanan = ((double) (b * n + 1 - t) / (double) b);
        ll tmp = (ll)ceil(kanan);
        cout << max(0ll,tmp) << endl;
        return 0;
    }
    long double atas = (long double) (t * (k - 1) + b) / (long double) (k - 1 + b);
    // cout << atas << endl;
    long double bawah = 1.0 * k;
    long double ret = log(atas) / log(bawah);
    ll ans = (ll)floor(ret);
    cout << max(0ll,n - ans) << endl;
    return 0;
}