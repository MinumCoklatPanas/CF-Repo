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
    ll n,d;
    cin >> n >> d;
    d *= d;
    int ans = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        ll x,y;
        cin >> x >> y;
        ll k = x * x + y * y;
        ans += (k <= d);
    }
    cout << ans << endl;
    return 0;
}