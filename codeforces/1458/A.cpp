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
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &it : a) cin >> it;
    vector<int> b(m);
    for (auto &it : b) cin >> it;
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    // cout << __gcd(24,48) << endl;
    int gcd = (n > 1 ? a[0] - a[1] : 0);
    for (int i = 1 ; i + 1 < n ; i++)
    {
        gcd = __gcd(gcd,a[i] - a[i + 1]);
        // cout << a[i] - a[i + 1] << " " << gcd << endl;
    }
    for (int i = 0 ; i < m ; i++)
    {
        int ans = __gcd(a[0] + b[i],gcd);
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}