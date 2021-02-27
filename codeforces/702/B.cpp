#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
#define int long long
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    map<int,int> mp;
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        for (int j = 0 ; j < 32 ; j++) if ((1ll << j) > ta)
        {
            int rem = abs((1ll << j) - ta);
            ans += mp[rem];
        }
        mp[ta]++;
    }
    cout << ans << endl;
    return 0;
}