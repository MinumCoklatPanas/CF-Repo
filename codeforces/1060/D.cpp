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
    int n;
    cin >> n;
    vector<int> l(n),r(n);
    for (int i = 0 ; i < n ; i++)
        cin >> l[i] >> r[i];
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    int ans = n;
    for (int i = 0 ; i < n ; i++)
        ans += max(l[i],r[i]);
    cout << ans << endl;
    return 0;
}