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
    int a,b,n;
    cin >> a >> b >> n;
    while (n--)
    {
        int l,t,m;
        cin >> l >> t >> m;

        if (a + (l - 1) * b > t)
        {
            cout << "-1\n";
            continue;
        }

        const auto cek = [&](int x) -> bool
        {
            int mx = a + (x - 1) * b;
            if (mx > t) return 0;
            int awal = a + (l - 1) * b;
            int sum = ((mx + awal) * (x - l + 1)) / 2;
            return (sum <= t * m);
        };

        int lo = l;
        int hi = 1000000;
        while (hi - lo > 1)
        {
            int mid = (lo + hi) / 2;
            if (cek(mid))
                lo = mid;
            else
                hi = mid - 1; 
        }
        if (cek(hi))
            cout << hi << endl;
        else
        if (cek(lo))
            cout << lo << endl;
        else
            cout << "-1\n";
    }
    return 0;
}